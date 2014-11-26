#include "DropXp.hpp"

DropXp::DropXp(sf::Vector2f position){
	type = 'x';
	texture.loadFromFile("images/dropXp.png");
	sprite.setTexture(texture);
	sprite.setPosition(position.x,position.y);
	this->start();
}

DropXp::DropXp(float x, float y){
	type = 'x';
	texture.loadFromFile("images/dropXp.png");
	sprite.setTexture(texture);
	sprite.setPosition(x,y);
	this->start();
}