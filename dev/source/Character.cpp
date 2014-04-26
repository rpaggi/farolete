#include "Character.hpp"

Character::Character(float screen_x, float screen_y){
  //Defines the mass center of person using the screen size pushed from parameter
  massCenter.x = screen_x/2;
  massCenter.y = screen_y/2;

  //Load the texture map
  texture.loadFromFile("images/character/character.png");

  //Load texture into sprite
  sprite.setTexture(texture);

  frameSize.x = 100;
  frameSize.y = 100;

  //Configure sprite frame
  sprite.setTextureRect(sf::IntRect(0, 0, 100, 100));
  sprite.setPosition((screen_x/2)-50,(screen_y/2)-50);

}

sf::Sprite Character::getSprite(){
	return sprite;
}

#include <iostream>
void Character::calculateAngle(float x, float y){
	float distance_x = x-massCenter.x;
	float distance_y = y-massCenter.y;

	float distance = sqrt(pow(distance_x, 2.0) + pow(distance_y,2.0));

	float s = distance_y/distance;
	float c = distance_x/distance;
	float ang = (atan2(s, c) * 180 / PI);
	if (ang < 0){
		ang += 360;
	}
	std::cout<<ang<<std::endl;
	changeSprite(ang);
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

void Character::setPosition(sf::Vector2f position){
	sprite.setPosition(position);
}