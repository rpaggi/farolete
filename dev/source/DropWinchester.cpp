#include "DropWinchester.hpp"

DropWinchester::DropWinchester(sf::Vector2f position){
   type = 'g';
   gunId = 5;
   texture.loadFromFile("images/dropWinchester.png");
   sprite.setTexture(texture);
   sprite.setPosition(position.x,position.y);
   this->start();
   this->collisionObject->position.x  = this->sprite.getPosition().x + 5;
   this->collisionObject->position.y  = this->sprite.getPosition().y + 5;
   this->collisionObject->size.x      = this->texture.getSize().x - 10;
   this->collisionObject->size.y      = this->texture.getSize().y - 10;
}

DropWinchester::DropWinchester(float x, float y){
   type = 'g';
   gunId = 5;
   texture.loadFromFile("images/dropWinchester.png");
   sprite.setTexture(texture);
   sprite.setPosition(x,y);
   this->start();
   this->collisionObject->position.x  = this->sprite.getPosition().x + 5;
   this->collisionObject->position.y  = this->sprite.getPosition().y + 5;
   this->collisionObject->size.x      = this->texture.getSize().x - 10;
   this->collisionObject->size.y      = this->texture.getSize().y - 10;
}

int DropWinchester::getGunId(){
   return gunId;
}