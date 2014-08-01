#include "CollisionObject.hpp"

CollisionObject::CollisionObject(){

}

CollisionObject::~CollisionObject(){

}

void CollisionObject::includeEvent(int e){
	events.push_back(e);
}

void CollisionObject::clearEvents(){
	events.clear();
}