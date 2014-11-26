#ifndef DROPMAUSER_HPP
#define DROPMAUSER_HPP

#include "DropItem.hpp"
#include <SFML/System/Vector2.hpp>

class DropMauser : public DropItem{
private:
	int     gunId;
public:
	DropMauser(sf::Vector2f position);
	DropMauser(float x, float y);

	int getGunId();
};

#endif