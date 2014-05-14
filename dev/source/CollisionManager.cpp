#include "CollisionManager.hpp"

CollisionObject::CollisionObject(sf::Vector2f p, sf::Vector2f s, std::string t){
	id = 0;
	type = t;
	position = p;
	size= s;
}

CollisionObject::~CollisionObject(){

}

CollisionManager::CollisionManager(){

}

void CollisionManager::include(CollisionObject * cObj){
	cObj->id = collisionObjects[collisionObjects.size()-1]->id + 1;
	collisionObjects.push_back(cObj);
}

std::string CollisionManager::test(CollisionObject * cObj){
	for(unsigned i=0;i<collisionObjects.size();i++){
		if(cObj->id != collisionObjects[i]->id){
			if((cObj->position.x+cObj->size.x > collisionObjects[i]->position.x)
			&& (cObj->position.x < collisionObjects[i]->position.x+collisionObjects[i]->size.x)
			&& (cObj->position.y+cObj->size.y > collisionObjects[i]->position.y)
			&& (cObj->position.y < collisionObjects[i]->position.y+collisionObjects[i]->size.y)){
				return collisionObjects[i]->type;
			}
		}
	}
	return "n";	
}

void CollisionManager::remove(CollisionObject * cObj){
	unsigned i;

	for(unsigned i=0;i<collisionObjects.size();i++){
		if(collisionObjects[i]->id == cObj->id){
			collisionObjects.erase(collisionObjects.begin() + i);
			break;
		}
	}

	while(i<collisionObjects.size()){
		collisionObjects[i]->id--;
		i++;
	}
}