#include "DropBullets.hpp"

DropBullets::DropBullets(sf::Vector2f position){
	type = 'b';
	texture.loadFromFile("images/drop/dropBullets.png");
	sprite.setTexture(texture);
	sprite.setPosition(position.x,position.y);
	this->start();
}

DropBullets::DropBullets(float x, float y){
	type = 'b';
	texture.loadFromFile("images/drop/dropBullets.png");
	sprite.setTexture(texture);
	sprite.setPosition(x,y);
	this->start();
}