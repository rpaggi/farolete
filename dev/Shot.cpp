#include "Shot.hpp"

//Remove this shit mother fucker!
#include <iostream>
#include <cmath>

#define PI 3.14159265


Shot::Shot(float pX, float pY, float dX, float dY){
	position.x = pX;
	position.y = pY;

	destination.x = dX;
	destination.y = dY;

	//Calculate the increment
	float aX, aY, iX, iY, distance, s, c, vel;

	aX = dX-pX;
	aY = dY-pY;

	distance = sqrt(pow(aX, 2.0) + pow(aY,2.0));

	s = aY/distance;
	c = aX/distance;

	vel = 15;

	iX = vel * c;
	iY = vel * s;

	increment.x = iX;
	increment.y = iY;

	texture.loadFromFile("shot/texture.png");
	sprite.setTexture(texture);

}

Shot::~Shot(){
}

void Shot::setPosition(float x, float y){
	position.x = x;
	position.y = y;
}

void Shot::setDestination(float x, float y){
	destination.x = x;
	destination.y = y;
}

bool Shot::moveShot() {
	time = clock.getElapsedTime();
	elapsed = time.asSeconds();
	bool controlReturn = true;

	if (elapsed > 0.005) {
		clock.restart();
		position.x += increment.x;
		position.y += increment.y;

		if (increment.x < 0 && increment.y < 0) {
			if ((position.x + increment.x) <= destination.x && (position.y + increment.y) <= destination.y)
				controlReturn = false;
		} else if (increment.x > 0 && increment.y < 0) {
			if ((position.x + increment.x) >= destination.x && (position.y + increment.y) <= destination.y)
				controlReturn = false;
		} else if (increment.x < 0 && increment.y > 0) {
			if ((position.x + increment.x) <= destination.x && (position.y + increment.y) >= destination.y)
				controlReturn = false;
		} else if (increment.x > 0 && increment.y > 0) {
			if ((position.x + increment.x) >= destination.x && (position.y + increment.y) >= destination.y)
				controlReturn = false;
		}
		if (controlReturn == true) {
			position.x += increment.x;
			position.y += increment.y;
			sprite.setPosition(position.x,position.y);
		} else {
			return false;
		}

	}
	return true;

}

sf::Sprite Shot::getSprite(){
	return sprite;
}
