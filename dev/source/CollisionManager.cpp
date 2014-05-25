#include "CollisionManager.hpp"
#include <iostream>
CollisionObject::CollisionObject(){

}

CollisionObject::~CollisionObject(){

}

CollisionManager::CollisionManager(){

}

void CollisionManager::include(tmx::MapLoader * mapLoader){
	for(auto layer = mapLoader->GetLayers().begin(); layer != mapLoader->GetLayers().end(); ++layer){
		if(layer->name == "CollisionHard"){
			for(auto object = layer->objects.begin(); object != layer->objects.end(); ++object){
				CollisionObject * cObj = new CollisionObject();

				cObj->type     = "ch";
				cObj->position = object->GetPosition();
				cObj->size     = object->GetSize();
				
         		if(collisionObjects.size() > 0){
					cObj->id = collisionObjects[collisionObjects.size()-1]->id + 1;
				}else{
					cObj->id = 1;
				}

        		collisionObjects.push_back(cObj);
        	}
		}else if(layer->name == "CollisionSoft"){
			for(auto object = layer->objects.begin(); object != layer->objects.end(); ++object){
				CollisionObject * cObj = new CollisionObject();
				float marginOut = 15.f;
				cObj->type       = "cs";
				cObj->position   = object->GetPosition();
				cObj->position.x+= marginOut;
				cObj->position.y+= marginOut;
				cObj->size       = object->GetSize();
				cObj->size.x    -= marginOut*2;
				cObj->size.y    -= marginOut*2;
				
         		if(collisionObjects.size() > 0){
					cObj->id = collisionObjects[collisionObjects.size()-1]->id + 1;
				}else{
					cObj->id = 1;
				}

        		collisionObjects.push_back(cObj);
        	}
		}
	}

}

void CollisionManager::include(CollisionObject * cObj){
	if(collisionObjects.size() > 0){
		cObj->id = collisionObjects[collisionObjects.size()-1]->id + 1;
	}else{
		cObj->id = 1;
	}
	
	collisionObjects.push_back(cObj);
}

std::string CollisionManager::test(CollisionObject * cObj, sf::Vector2f destination){
	for(unsigned i=0;i < collisionObjects.size();i++){
		if(cObj->id != collisionObjects[i]->id){
			if((cObj->position.x+destination.x+cObj->size.x > collisionObjects[i]->position.x)
			&& (cObj->position.x+destination.x < collisionObjects[i]->position.x+collisionObjects[i]->size.x)
			&& (cObj->position.y+destination.y+cObj->size.y > collisionObjects[i]->position.y)
			&& (cObj->position.y+destination.y < collisionObjects[i]->position.y+collisionObjects[i]->size.y)){
				return collisionObjects[i]->type;
			}
		}
	}
	return "n";	
}

std::string CollisionManager::test(CollisionObject * cObj){
	for(unsigned i=0;i < collisionObjects.size();i++){
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
}