///source for map object class///
#include <MapObject.h>

using namespace tmx;

///--------poly segment--------///
bool MapObject::Segment::Intersects(const MapObject::Segment& segment)
{
	sf::Vector2f s1 = End - Start;
	sf::Vector2f s2 = segment.End - segment.Start;

	float s, t;
	s = (-s1.y * (Start.x - segment.Start.x) + s1.x * (Start.y - segment.Start.y)) / (-s2.x * s1.y + s1.x * s2.y);
	t = ( s2.x * (Start.y - segment.Start.y) - s2.y * (Start.x - segment.Start.x)) / (-s2.x * s1.y + s1.x * s2.y);

	if (s >= 0 && s <= 1 && t >= 0 && t <= 1)
	{
		// Collision detected

		//point at which lines intersect - do what you will with this
		sf::Vector2f intersection(Start.x + (t * s1.x), Start.y + (t * s1.y));
		return true;
	}						
	return false;
}





///------map object-------///

//ctor
MapObject::MapObject()
	 : m_visible	(true),
	 m_rotation		(0.f),
	 m_shape		(Rectangle),
	 m_furthestPoint(0.f)
{
	m_debugShape.setPrimitiveType(sf::LinesStrip);

	//this loads a font for text output during debug drawing
	//you need to select your own font here as SFML no longer
	//supports a default font. If you do not plan to use this
	//during debugging it can be ignored.
	if(!m_debugFont.loadFromFile("assets/fonts/default.ttf"))
	{
		//feel free to supress these messages
		std::cout << "If you wish to output text during debugging please specify a font file in the map object class" << std::endl;
		std::cout << "If you do not wish to use debug output this can be safely ignored." << std:: endl;
	}
}

//public
std::string MapObject::GetPropertyString(const std::string& name)
{
	if(m_properties.find(name) != m_properties.end())
		return m_properties[name];
	else
		return std::string();
}

void MapObject::SetProperty(const std::string& name, const std::string& value)
{
	m_properties[name] = value;
}

void MapObject::SetPosition(const sf::Vector2f& position)
{
	sf::Vector2f distance = position - m_position;
	Move(distance);
}

void MapObject::Move(const sf::Vector2f& distance)	
{
	//update properties by movement amount
	m_centrePoint += distance;
	for(auto p : m_polypoints)
		p += distance;
			
	for(auto i = 0u; i < m_debugShape.getVertexCount(); ++i)
		m_debugShape[i].position += distance;

	m_AABB.left += distance.x;
	m_AABB.top += distance.y;

	//set new position
	m_position += distance;			
}

bool MapObject::Contains(sf::Vector2f point) const	
{
	if(m_shape == Polyline) return false;

	//convert point to local coords
	point-= m_position;

	//rotate point relative to object rotation
	if(m_rotation)
	{
		sf::Transform tf;
		tf.rotate(-m_rotation);
		point = tf.transformPoint(point);
	}

	//check if enough poly points
	if(m_polypoints.size() < 3) return false;

	//else raycast through points
	unsigned int i, j;
	bool result = false;
	for (i = 0, j = m_polypoints.size() - 1; i < m_polypoints.size(); j = i++)
	{
		if (((m_polypoints[i].y > point.y) != (m_polypoints[j].y > point.y)) &&
		(point.x < (m_polypoints[j].x - m_polypoints[i].x) * (point.y - m_polypoints[i].y)
			/ (m_polypoints[j].y - m_polypoints[i].y) + m_polypoints[i].x))
				result = !result;
	}
	return result;
}

bool MapObject::Intersects(const MapObject& object) const
{
	//check if distance between objects is less than sum of furthest points
	float distance = Helpers::Vectors::GetLength(m_centrePoint + object.m_centrePoint);
	if(distance > (m_furthestPoint + object.m_furthestPoint)) return false;

	//check intersection if either object contains a point of the other
	for(auto& p : object.m_polypoints)
		if(Contains(p + object.GetPosition())) return true;

	for(auto& p : m_polypoints)
		if(object.Contains(p + GetPosition())) return true;

	return false;
}

void MapObject::CreateDebugShape(const sf::Color& colour)
{
	//reset any existing shapes incase new points have been added
	m_debugShape.clear();
			
	//draw poly points
	for(auto i = m_polypoints.cbegin(); i != m_polypoints.cend(); ++i)
		m_debugShape.append(sf::Vertex(*i + m_position, colour));

	if(m_shape != Polyline)
	{
		//close shape by copying first point to end
		m_debugShape.append(m_debugShape[0]);
	}

	//precompute shape values for intersection testing
	m_CalcTestValues();

	//create the AABB for quad tree testing
	m_CreateAABB();
}

void MapObject::DrawDebugShape(sf::RenderTarget& rt) const
{
	rt.draw(m_debugShape);
	sf::Text text(m_name, m_debugFont, 14u);
	text.setPosition(m_position);
	text.setColor(sf::Color::Black);
	rt.draw(text);
}

sf::Vector2f MapObject::FirstPoint() const
{
	if(!m_polypoints.empty())
		return m_polypoints[0] + m_position;
	else return sf::Vector2f();
}

sf::Vector2f MapObject::LastPoint() const
{
	if(!m_polypoints.empty())
		return(m_polypoints.back() + m_position);
	else return sf::Vector2f();
}

sf::Vector2f MapObject::CollisionNormal(const sf::Vector2f& start, const sf::Vector2f& end) const
{
	Segment trajectory(start, end);
	for(auto& s : m_polySegs)
	{
		if(trajectory.Intersects(s))
		{
			sf::Vector2f v = s.End - s.Start;
			sf::Vector2f n(v.y, -v.x);
			//invert normal if pointing in wrong direction
			float tAngle = Helpers::Vectors::GetAngle(end - start);
			float nAngle = Helpers::Vectors::GetAngle(n);
			if(nAngle - tAngle > 90.f) n =- n;

			return Helpers::Vectors::Normalize(n);
		}
	}
	return Helpers::Vectors::Normalize(end - start);
}

void MapObject::CreateSegments()
{
	for(auto i = 0u; i < m_polypoints.size() - 1; i++)
	{
		m_polySegs.push_back(Segment(m_polypoints[i], m_polypoints[i + 1]));
	}
	if(m_shape != Polyline) //close shape
		m_polySegs.push_back(Segment(*(m_polypoints.end() - 1), *m_polypoints.begin()));

	std::cout << "Added " << m_polySegs.size() << " segments to Map Object" << std::endl;
}


//private
sf::Vector2f MapObject::m_CalcCentre() const
{
	if(m_shape == Polyline) return sf::Vector2f();

	if(m_shape == Rectangle || m_polypoints.size() < 3)
	{
		//we don't have a triangle so use bounding box
		return sf::Vector2f(m_position.x + (m_size.x / 2.f), m_position.y + (m_size.y / 2.f));
	}
	//calc centroid of poly shape
	sf::Vector2f centroid;
	float signedArea = 0.f;
	float x0 = 0.f; // Current vertex X
	float y0 = 0.f; // Current vertex Y
	float x1 = 0.f; // Next vertex X
	float y1 = 0.f; // Next vertex Y
	float a = 0.f;  // Partial signed area

	// For all vertices except last
	unsigned i;
	for(i = 0; i < m_polypoints.size() - 1; ++i)
	{
		x0 = m_polypoints[i].x;
		y0 = m_polypoints[i].y;
		x1 = m_polypoints[i + 1].x;
		y1 = m_polypoints[i + 1].y;
		a = x0 * y1 - x1 * y0;
		signedArea += a;
		centroid.x += (x0 + x1) * a;
		centroid.y += (y0 + y1) * a;
	}

	// Do last vertex
	x0 = m_polypoints[i].x;
	y0 = m_polypoints[i].y;
	x1 = m_polypoints[0].x;
	y1 = m_polypoints[0].y;
	a = x0 * y1 - x1 * y0;
	signedArea += a;
	centroid.x += (x0 + x1) * a;
	centroid.y += (y0 + y1) * a;

	signedArea *= 0.5;
	centroid.x /= (6 * signedArea);
	centroid.y /= (6 * signedArea);

	//convert to world space
	centroid += m_position;
	return centroid;
}

void MapObject::m_CalcTestValues()
{
	m_centrePoint = m_CalcCentre();
	for(auto i = m_polypoints.cbegin(); i != m_polypoints.cend(); ++i)
	{
		float length = Helpers::Vectors::GetLength(*i - m_centrePoint);
		if(m_furthestPoint < length)
		{
			m_furthestPoint = length;
			if(m_shape == Polyline) m_centrePoint = *i / 2.f;
		}
	}
	//polyline centre ought to be half way between the start point and the furthest vertex
	if(m_shape == Polyline) m_furthestPoint /= 2.f;
}

void MapObject::m_CreateAABB()
{
	if(!m_polypoints.empty())
	{
		m_AABB = sf::FloatRect(m_polypoints[0], m_polypoints[0]);
		for(auto point = m_polypoints.cbegin(); point != m_polypoints.cend(); ++point)
		{
			if(point->x < m_AABB.left) m_AABB.left = point->x;
			if(point->x > m_AABB.width) m_AABB.width = point->x;
			if(point->y < m_AABB.top) m_AABB.top = point->y;
			if(point->y > m_AABB.height) m_AABB.height = point->y;
		}

		//calc true width and height by distance between points
		m_AABB.width -= m_AABB.left;
		m_AABB.height -= m_AABB.top;

		//offset into world position
		m_AABB.left += m_position.x;
		m_AABB.top += m_position.y;


		//debug draw AABB
		//m_debugShape.append(sf::Vector2f(m_AABB.left, m_AABB.top));
		//m_debugShape.append(sf::Vector2f(m_AABB.left + m_AABB.width, m_AABB.top));
		//m_debugShape.append(sf::Vector2f(m_AABB.left + m_AABB.width, m_AABB.top + m_AABB.height));
		//m_debugShape.append(sf::Vector2f(m_AABB.left, m_AABB.top + m_AABB.height));
	}
}