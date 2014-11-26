#ifndef DROPXP_HPP
#define DROPXP_HPP

#include "DropItem.hpp"
#include <SFML/System/Vector2.hpp>

class DropXp : public DropItem{
public:
	DropXp(sf::Vector2f position);
	DropXp(float x, float y);
};

#endif