#ifndef DROPSTAMINA_HPP
#define DROPSTAMINA_HPP

#include "DropItem.hpp"
#include <SFML/System/Vector2.hpp>

class DropStamina : public DropItem{
public:
	DropStamina(sf::Vector2f position);
	DropStamina(float x, float y);
};

#endif