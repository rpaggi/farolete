#include "CharMain.hpp"
#include <iostream>

CharMain::CharMain(float screen_x, float screen_y){
 //Defines the mass center of person using the screen size pushed from parameter
  massCenter.x = screen_x/2;
  massCenter.y = screen_y/2;

  //Load the texture map
  texture.loadFromFile("images/character/character.png");

  //Load texture into sprite
  sprite.setTexture(texture);

  frameSize.x = 100;
  frameSize.y = 100;

  collisionMagin.x = -18.f;
  collisionMagin.y = -10.f;

  //Configure sprite frame
  sprite.setTextureRect(sf::IntRect(0, 0, frameSize.x, frameSize.y));
  sprite.setPosition((screen_x/2)-frameSize.x,(screen_y/2)-frameSize.y);

  sf::Vector2f screen_size;
  screen_size.x = screen_x;
  screen_size.y = screen_y;
  renderTexture.create(screen_x, screen_y);
  bullets = new Bullets(massCenter, screen_size);
  collisionObject = new CollisionObject();
}

bool CharMain::update(float x, float y){
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

	if(collisionManager->test(collisionObject) != "n"){
	 	return false;
	 }

	return true;
}

void CharMain::move(sf::Vector2f pos){
	position.x = pos.x-(frameSize.x/2);
	position.y = pos.y-(frameSize.y/2);
	sprite.setPosition(position.x, position.y);
	collisionObject->position = position;
	collisionObject->position.x-= collisionMagin.x;
	collisionObject->position.y-= collisionMagin.y;
}

bool CharMain::testCollisionMovement(sf::Vector2f destination){
	if(collisionManager->test(collisionObject, destination) != "n"){
		return false;
	}
	return true;
}

void CharMain::setCollisionManager(CollisionManager * cManager){
	collisionManager            = cManager;
	collisionObject->type       = "c";
	
	collisionObject->position   = position;
	collisionObject->position.x-= collisionMagin.x;
	collisionObject->position.y-= collisionMagin.y;

	collisionObject->size.x     = frameSize.x+(collisionMagin.x*2);
	collisionObject->size.y     = frameSize.y+(collisionMagin.y*2);
	collisionManager->include(collisionObject);
}