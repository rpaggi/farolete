#ifndef DROPMAUSER_HPP
#define DROPMAUSER_HPP

#include "DropItem.hpp"
#include <SFML/System/Vector2.hpp>

class DropMauser : public DropItem{
private:
public:
	DropMauser(sf::Vector2f position);
	DropMauser(float x, float y);
};

#endif