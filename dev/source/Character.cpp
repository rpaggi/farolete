#include "Character.hpp"
#include <iostream>

Character::Character(){

}

sf::Sprite Character::getSprite(){
	sf::Sprite spriteTemp;

	renderTexture.clear(sf::Color(255,255,255,0));
	renderTexture.draw(bullets->getSprite());
	renderTexture.draw(sprite);
	renderTexture.display();

	sf::View view = renderTexture.getView();
	spriteTemp.setTexture(renderTexture.getTexture());
	spriteTemp.setPosition(((view.getCenter().x*2) - view.getSize().x)/2,
		                   ((view.getCenter().y*2) - view.getSize().y)/2);

	return spriteTemp;
}

void Character::changeSprite(float angle){
	 if((angle>=0 && angle<32.195) || (angle>=328.8 && angle<=360)){
	 	sprite.setTextureRect(sf::IntRect(0, frameSize.y*2, 100, 100));
	 }else if(angle>=32.195 && angle<152.276){
	 	sprite.setTextureRect(sf::IntRect(0, frameSize.y*1, 100, 100));
	 }else if(angle>=152.276 && angle<206.8){
	 	sprite.setTextureRect(sf::IntRect(0, frameSize.y*3, 100, 100));
	 }else if(angle>=206.8 && angle<328.8){
	 	sprite.setTextureRect(sf::IntRect(0, frameSize.y*4, 100, 100));
	 }
}



void Character::move(sf::Vector2f position){
	this->position.x = position.x-(frameSize.x/2);
	this->position.y = position.y-(frameSize.y/2);
	sprite.setPosition(this->position.x, this->position.y);
}
void Character::move(float x, float y){	
	sprite.setPosition(x-(frameSize.x/2), y-(frameSize.y/2));
	position.x = x-(frameSize.x/2);
	position.y = y-(frameSize.y/2);
}

void Character::setView(sf::View view){
	renderTexture.setView(view);
	bullets->setView(view);
}

void Character::pushTrigger(sf::Vector2f dest){
	bullets->includeBullet(dest);
}