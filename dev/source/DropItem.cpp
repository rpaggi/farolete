#include "DropItem.hpp"
#include <iostream>

DropItem::DropItem(){
}

void DropItem::start(){
   this->id                           = 0;
   this->collisionObject              = new CollisionObject();
   this->collisionObject->position.x  = this->sprite.getPosition().x + 10;
   this->collisionObject->position.y  = this->sprite.getPosition().y + 10;
   this->collisionObject->size.x      = this->texture.getSize().x - 20;
   this->collisionObject->size.y      = this->texture.getSize().y - 20;
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