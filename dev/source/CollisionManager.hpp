#ifndef COLLISIONMANAGER_HPP
#define COLLISIONMANAGER_HPP

#include <SFML/System/Vector2.hpp>
#include <vector>
#include <string>
#include <MapLoader.h>

class CollisionObject{
public:
	int          id;
	std::string  type;
	sf::Vector2f size;
	sf::Vector2f position;

	CollisionObject();

	~CollisionObject();
};

class CollisionManager{
private:
	std::vector<CollisionObject *> collisionObjects;

public:
	CollisionManager();

	void include(tmx::MapLoader * mapLoader);

	void include(CollisionObject * cObj);

	std::string test(CollisionObject * cObj);
    std::string test(CollisionObject * cObj, sf::Vector2f destination);

	void remove(CollisionObject * cObj);
};

#endif
