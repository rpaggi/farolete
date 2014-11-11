#include "DropManager.hpp"
#include <iostream>

DropManager::DropManager(Display * display, float areaX, float areaY, CollisionManager * collisionManager){
   this->display = display;
   this->collisionManager = collisionManager;
   area.x = areaX;
   area.y = areaY;
}

void DropManager::include(DropItem item){
   if(vetor.size() > 0){
      item.setId(vetor[vetor.size()-1]->getId() + 1);
   }else{
      item.setId(1);
   }

   vetor.push_back(&item);
}

void DropManager::update(){
   for(unsigned i=0;i<vetor.size();i++){
      CollisionObject cObj = collisionManager->testGetObject(vetor[i]->getCollisionObject(), "c");
      if(cObj.type == "c"){
         char type = vetor[i]->getType();
         if(type == 's'){
            collisionManager->includeEventToObject(-1, cObj.id);
         }
         collisionManager->remove(vetor[i]->getCollisionObject());
         vetor.erase(vetor.begin() + i);
      }
   }
}

void DropManager::draw(){
   for(unsigned i=0;i<vetor.size();i++){
      display->draw(vetor[i]->getSprite());
   }
}

void DropManager::sortItem(float x, float y){
   int rItem     = RandomInteger(1, 1);

   if (rItem == 1){
      DropStamina * dStamina = new DropStamina(x, y);
      collisionManager->include(dStamina->getCollisionObject());
      vetor.push_back(dStamina);
   }
}