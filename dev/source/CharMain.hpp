#ifndef CHARMAIN_HPP
#define CHARMAIN_HPP

#include "Character.hpp"
#include "CollisionManager.hpp"

class CharMain : public Character {	
private:
	CollisionManager* collisionManager;
	CollisionObject * collisionObject;
	sf::Vector2f      collisionMagin;
public:
	CharMain(float screen_x, float screen_y);

	bool update(float x, float y);

	void move(sf::Vector2f pos);

	bool testCollisionMovement(sf::Vector2f destination);

	void setCollisionManager(CollisionManager * cManager);
};

#endif