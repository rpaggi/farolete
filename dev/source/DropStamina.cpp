#include "DropStamina.hpp"

DropStamina::DropStamina(sf::Vector2f position){
	type = 's';
	texture.loadFromFile("images/stamina.png");
	sprite.setTexture(texture);
	sprite.setPosition(position.x,position.y);
	this->start();
}

DropStamina::DropStamina(float x, float y){
	type = 's';
	texture.loadFromFile("images/stamina.png");
	sprite.setTexture(texture);
	sprite.setPosition(x,y);
	this->start();
}