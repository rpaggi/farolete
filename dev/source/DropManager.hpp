#ifndef DROPMANAGER_HPP
#define DROPMANAGER_HPP

#include <vector>

#include "Display.hpp"
#include "DropStamina.hpp"
#include "CollisionManager.hpp"
#include "Random.hpp"

class DropManager{
private:
	Display              *   display;
	CollisionManager     *   collisionManager;
	std::vector<DropItem *>  vetor;
	sf::Vector2f             area;
public:
	DropManager(Display * display, float areaX, float areaY, CollisionManager * collisionManager);

	void include(DropItem);
	void update();
	void draw();
	void sortItem(float, float);
};

#endif