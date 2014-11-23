#include "DropManager.hpp"
#include <iostream>

DropManager::DropManager(Display * display, float areaX, float areaY, CollisionManager * collisionManager){
   this->display = display;
   this->collisionManager = collisionManager;
   area.x = areaX;
   area.y = areaY;

   verdana.loadFromFile("images/hud/verdanab.ttf");
   message.setFont(verdana);
   message.setCharacterSize(18);
   message.setColor(sf::Color(200, 200, 200));
   message.setString("Pressione C para pegar a arma");

   showMessage = false;
   getGun = false;
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
   showMessage = false;
   message.setPosition((display->getView().getCenter().x)-140, (display->getView().getCenter().y - display->getSize().y/2) + 20);

   for(unsigned i=0;i<vetor.size();i++){
      CollisionObject cObj = collisionManager->testGetObject(vetor[i]->getCollisionObject(), "c");
      if(cObj.type == "c"){
         char type = vetor[i]->getType();
         if(type == 's'){
            collisionManager->includeEventToObject(-1, cObj.id);
            collisionManager->remove(vetor[i]->getCollisionObject());
            vetor.erase(vetor.begin() + i);
         }else if(type == 'h'){
            collisionManager->includeEventToObject(-2, cObj.id);
            collisionManager->remove(vetor[i]->getCollisionObject());
            vetor.erase(vetor.begin() + i);
         }else if(type == 'b'){
            collisionManager->includeEventToObject(-3, cObj.id);
            collisionManager->remove(vetor[i]->getCollisionObject());
            vetor.erase(vetor.begin() + i);
         }else if(type == 'g'){
            showMessage = true;
            if(getGun){
               collisionManager->remove(vetor[i]->getCollisionObject());
               vetor.erase(vetor.begin() + i);
               getGun = false;
            }
         }
      }
   }
}

void DropManager::draw(){
   for(unsigned i=0;i<vetor.size();i++){
      display->draw(vetor[i]->getSprite());
   }

   if(showMessage){
      display->draw(message);
   }
}

void DropManager::sortItem(float x, float y){
   int rItem     = RandomInteger(1, 3);

   if (rItem == 1){
      DropStamina * dStamina = new DropStamina(x, y);
      collisionManager->include(dStamina->getCollisionObject());
      vetor.push_back(dStamina);
   }else if(rItem == 2){
      DropHealth * dHealth = new DropHealth(x, y);
      collisionManager->include(dHealth->getCollisionObject());
      vetor.push_back(dHealth);
   }else if(rItem == 3){
      DropBullets * dBullets = new DropBullets(x, y);
      collisionManager->include(dBullets->getCollisionObject());
      vetor.push_back(dBullets);
   }
}

void DropManager::sortItem(sf::Vector2f position){
   this->sortItem(position.x, position.y);
}

void DropManager::dropGun(int gunId, float x, float y){
   DropItem * dGun;
   if(gunId == 2 || gunId == 3){
      dGun = new DropColt(x, y);
   }

   collisionManager->include(dGun->getCollisionObject());
   vetor.push_back(dGun);
}

void DropManager::getGunOn(){
   getGun = true;
}