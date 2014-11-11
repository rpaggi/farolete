#include "DropItem.hpp"
#include <iostream>

DropItem::DropItem(){
}

void DropItem::start(){
   this->id                           = 0;
   this->collisionObject              = new CollisionObject();
   this->collisionObject->position.x  = this->sprite.getPosition().x;
   this->collisionObject->position.y  = this->sprite.getPosition().y;
   this->collisionObject->size.x      = this->texture.getSize().x;
   this->collisionObject->size.y      = this->texture.getSize().y;
   this->collisionObject->type        = "d";
}

sf::Sprite DropItem::getSprite(){
   return sprite;
}

CollisionObject * DropItem::getCollisionObject(){
   return collisionObject;
}

int DropItem::getId(){
   return this->id;
}

void DropItem::setId(int id){
   this->id = id;
}

char DropItem::getType(){
   return this->type;
}