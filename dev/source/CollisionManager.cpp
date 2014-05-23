#include "CollisionManager.hpp"
#include <iostream>
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

void CollisionManager::include(tmx::MapLoader * mapLoader){
	std::cout<<"Including mapLoader objects"<<std::endl;
	for(auto layer = mapLoader->GetLayers().begin(); layer != mapLoader->GetLayers().end(); ++layer){
		if(layer->name == "CollisionHard"){
			std::cout<<"Layer name now is "<<layer->name<<std::endl;
			std::cout<<layer->objects.size()<<std::endl;
			for(auto object = layer->objects.begin(); object != layer->objects.end(); ++object){
        		sf::Vector2f teste = object->GetPosition();
            	std::cout<<"X:"<<teste.x<<" Y:"<<teste.y<<std::endl;

            	teste = object->GetSize();
            	std::cout<<"X:"<<teste.x<<" Y:"<<teste.y<<std::endl;
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
}