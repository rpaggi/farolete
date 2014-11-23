#include "DropHealth.hpp"

DropHealth::DropHealth(sf::Vector2f position){
	type = 'h';
	texture.loadFromFile("images/dropHealth.png");
	sprite.setTexture(texture);
	sprite.setPosition(position.x,position.y);
	this->start();
}

DropHealth::DropHealth(float x, float y){
	type = 'h';
	texture.loadFromFile("images/dropHealth.png");
	sprite.setTexture(texture);
	sprite.setPosition(x,y);
	this->start();
}