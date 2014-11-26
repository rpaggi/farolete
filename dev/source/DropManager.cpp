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
   elapsed = clock.getElapsedTime().asSeconds();

   showMessage = false;
   message.setPosition((display->getView().getCenter().x)-140, (display->getView().getCenter().y - display->getSize().y/2) + 20);

   for(unsigned i=0;i<vetor.size();i++){
      float itemTime = (elapsed - vetor[i]->getLastTime());

      if(itemTime < 15.0){
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
            }else if(type == 'x'){
               collisionManager->includeEventToObject(-4, cObj.id);
               collisionManager->remove(vetor[i]->getCollisionObject());
               vetor.erase(vetor.begin() + i);
            }else if(type == 'g'){
               showMessage = true;
               if(getGun){
                  if(vetor[i]->getGunId() == 2){
                     collisionManager->includeEventToObject(-11, cObj.id);
                  }else if(vetor[i]->getGunId() == 3){
                     collisionManager->includeEventToObject(-12, cObj.id);
                  }else if(vetor[i]->getGunId() == 4){
                     collisionManager->includeEventToObject(-13, cObj.id);
                  }else if(vetor[i]->getGunId() == 5){
                     collisionManager->includeEventToObject(-14, cObj.id);
                  }
                  collisionManager->remove(vetor[i]->getCollisionObject());
                  vetor.erase(vetor.begin() + i);
                  getGun = false;
               }
            }
         }
      }else{
         collisionManager->remove(vetor[i]->getCollisionObject());
         vetor.erase(vetor.begin() + i);
      }

   }
}

void DropManager::draw(){
   for(unsigned i=0;i<vetor.size();i++){
      float itemTime = (elapsed - vetor[i]->getLastTime());
      int itemTimeInt = itemTime;
      if(itemTime < 7.5 || itemTime >= 7.5 && itemTimeInt%2 == 0){
         display->draw(vetor[i]->getSprite());
      }
   }

   if(showMessage){
      display->draw(message);
   }
}

void DropManager::sortItem(float x, float y){
   int rItem     = RandomInteger(4, 16);

   rItem /= 4;

   if (rItem == 1){
      DropStamina * dStamina = new DropStamina(x, y);
      dStamina->setLastTime(elapsed);
      collisionManager->include(dStamina->getCollisionObject());
      vetor.push_back(dStamina);
   }else if(rItem == 2){
      DropHealth * dHealth = new DropHealth(x, y);
      dHealth->setLastTime(elapsed);
      collisionManager->include(dHealth->getCollisionObject());
      vetor.push_back(dHealth);
   }else if(rItem == 3){
      DropBullets * dBullets = new DropBullets(x, y);
      dBullets->setLastTime(elapsed);
      collisionManager->include(dBullets->getCollisionObject());
      vetor.push_back(dBullets);
   }else if(rItem == 4){
      DropXp * dXp = new DropXp(x, y);
      dXp->setLastTime(elapsed);
      collisionManager->include(dXp->getCollisionObject());
      vetor.push_back(dXp);
   }
}

void DropManager::sortItem(sf::Vector2f position){
   this->sortItem(position.x, position.y);
}

void DropManager::dropGun(int gunId, float x, float y){
   if(gunId == 2){
      DropColt * dGun = new DropColt(x, y);
      dGun->setLastTime(elapsed);
      collisionManager->include(dGun->getCollisionObject());
      vetor.push_back(dGun);
   }else if(gunId == 3){
      DropLuger * dGun = new DropLuger(x, y);
      dGun->setLastTime(elapsed);
      collisionManager->include(dGun->getCollisionObject());
      vetor.push_back(dGun);
   }else if(gunId == 4){
      DropMauser * dGun = new DropMauser(x, y);
      dGun->setLastTime(elapsed);
      collisionManager->include(dGun->getCollisionObject());
      vetor.push_back(dGun);
   }else if(gunId == 5){
      DropWinchester * dGun = new DropWinchester(x, y);
      dGun->setLastTime(elapsed);
      collisionManager->include(dGun->getCollisionObject());
      vetor.push_back(dGun);
   }
}

void DropManager::getGunOn(){
   getGun = true;
}