#ifndef DROPCOLT_HPP
#define DROPCOLT_HPP

#include "DropItem.hpp"
#include <SFML/System/Vector2.hpp>

class DropColt : public DropItem{
private:
public:
	DropColt(sf::Vector2f position);
	DropColt(float x, float y);
};

#endif