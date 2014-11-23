#ifndef DROPHEALTH_HPP
#define DROPHEALTH_HPP

#include "DropItem.hpp"
#include <SFML/System/Vector2.hpp>

class DropHealth : public DropItem{
public:
	DropHealth(sf::Vector2f position);
	DropHealth(float x, float y);
};

#endif