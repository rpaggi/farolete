#ifndef DROPLUGER_HPP
#define DROPLUGER_HPP

#include "DropItem.hpp"
#include <SFML/System/Vector2.hpp>

class DropLuger : public DropItem{
private:
public:
	DropLuger(sf::Vector2f position);
	DropLuger(float x, float y);
};

#endif