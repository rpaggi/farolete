#ifndef COLLISIONMANAGER_HPP
#define COLLISIONMANAGER_HPP

#include <SFML/System/Vector2.hpp>
#include <vector>
#include <string>
#include <MapLoader.h>

#include "CollisionObject.hpp"

class CollisionManager{
private:
	std::vector<CollisionObject *> collisionObjects;

public:
	CollisionManager();

	void include(tmx::MapLoader * mapLoader);

	void include(CollisionObject * cObj);

	std::string test(CollisionObject * cObj);
	std::string testVision(CollisionObject * cObj);
    std::string test(CollisionObject * cObj, sf::Vector2f destination);
    CollisionObject testGetObject(CollisionObject * cObj);
    std::string testCollisionSide(CollisionObject * cObj);

	void remove(CollisionObject * cObj);

	void includeEventToObject(int e, int id);
};

#endif
