#ifndef DROPBULLETS_HPP
#define DROPBULLETS_HPP

#include "DropItem.hpp"
#include <SFML/System/Vector2.hpp>

class DropBullets : public DropItem{
public:
	DropBullets(sf::Vector2f position);
	DropBullets(float x, float y);
};

#endif