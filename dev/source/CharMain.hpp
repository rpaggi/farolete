#ifndef CHARMAIN_HPP
#define CHARMAIN_HPP

#include "Character.hpp"
#include <string>

class CharMain : public Character {	
private:
	bool              hidden;
	bool              controlTrigger;

	void              changeSprite(float angle);
public:
	CharMain(float screen_x, float screen_y, CollisionManager * cManager);

	void update(float x, float y);

	void move(sf::Vector2f pos);

	bool testCollisionMovement(sf::Vector2f destination);

    void pushTrigger(sf::Vector2f dest);
};

#endif