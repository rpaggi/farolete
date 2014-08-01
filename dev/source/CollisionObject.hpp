#ifndef COLLISIONOBJECT_HPP
#define COLLISIONOBJECT_HPP

#include <SFML/System/Vector2.hpp>
#include <string>
#include <vector>

class CollisionObject{
public:
	int              id;
	std::string      type;
	sf::Vector2f     size;
	sf::Vector2f     position;
	std::vector<int> events; 

	CollisionObject();

	~CollisionObject();

	void includeEvent(int e);

	void clearEvents();
};

#endif
