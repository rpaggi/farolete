#include "Character.hpp"
#include <iostream>

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
  sprite.setPosition((screen_x/2)-frameSize.x,(screen_y/2)-frameSize.y);

  sf::Vector2f screen_size;
  screen_size.x = screen_x;
  screen_size.y = screen_y;
  renderTexture.create(screen_x, screen_y);
  bullets = new Bullets(massCenter, screen_size);
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

void Character::update(float x, float y){
	bullets->moveBullets();
	
	float distance_x = x-massCenter.x;
	float distance_y = y-massCenter.y;

	float distance = sqrt(pow(distance_x, 2.0) + pow(distance_y,2.0));

	float s = distance_y/distance;
	float c = distance_x/distance;
	float ang = (atan2(s, c) * 180 / PI);
	if (ang < 0){
		ang += 360;
	}
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
	sprite.setPosition(position.x-(frameSize.x/2), position.y-(frameSize.y/2));
}
void Character::setPosition(float x, float y){	
	sprite.setPosition(x-(frameSize.x/2), y-(frameSize.y/2));
}

void Character::setView(sf::View view){
	renderTexture.setView(view);
	bullets->setView(view);
}

void Character::pushTrigger(sf::Vector2f dest){
	bullets->includeBullet(dest);
}