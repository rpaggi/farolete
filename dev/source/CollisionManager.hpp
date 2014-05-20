#ifndef COLLISIONMANAGER_HPP
#define COLLISIONMANAGER_HPP

#include <SFML/System/Vector2.hpp>
#include <vector>
#include <string>

class CollisionObject{
public:
	int          id;
	std::string  type;
	sf::Vector2f position;
	sf::Vector2f size;

	CollisionObject(sf::Vector2f p, sf::Vector2f s, std::string t);

	~CollisionObject();
};

class CollisionManager{
	std::vector<CollisionObject *> collisionObjects;

public:
	CollisionManager();

	void include(CollisionObject * cObj);

	std::string test(CollisionObject * cObj);

	void remove(CollisionObject * cObj);
};

#endif
