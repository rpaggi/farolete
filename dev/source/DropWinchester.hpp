#ifndef DROPWINCHESTER_HPP
#define DROPWINCHESTER_HPP

#include "DropItem.hpp"
#include <SFML/System/Vector2.hpp>

class DropWinchester : public DropItem{
private:
	int     gunId;
public:
	DropWinchester(sf::Vector2f position);
	DropWinchester(float x, float y);

	int getGunId();
};

#endif