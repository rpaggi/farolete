#ifndef CHARMAIN_HPP
#define CHARMAIN_HPP

#include "Character.hpp"
#include "CollisionManager.hpp"
#include <string>

class CharMain : public Character {	
private:
	CollisionManager* collisionManager;
	CollisionObject * collisionObject;
	sf::Vector2f      collisionMagin;

	bool              hidden;

	void              changeSprite(float angle);
public:
	CharMain(float screen_x, float screen_y);

	void update(float x, float y);

	void move(sf::Vector2f pos);

	bool testCollisionMovement(sf::Vector2f destination);

	void setCollisionManager(CollisionManager * cManager);

    void pushTrigger(sf::Vector2f dest);
};

#endif