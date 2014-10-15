#include "CharMain.hpp"
#include <iostream>

CharMain::CharMain(float screen_x, float screen_y, CollisionManager * cManager){
   //Defines the mass center of person using the screen size pushed from parameter
   massCenter.x = screen_x/2;
   massCenter.y = screen_y/2;

   //Load the texture map
   texture.loadFromFile("images/character/character.png");

   //Load texture into sprite
   sprite.setTexture(texture);

   frameSize.x = 100;
   frameSize.y = 100;

   //Configure sprite frame
   sprite.setTextureRect(sf::IntRect(0, 0, frameSize.x, frameSize.y));
   sprite.setPosition((screen_x/2)-(frameSize.x/2),(screen_y/2)-(frameSize.y/2));
   position.x = (screen_x/2)-(frameSize.x/2);
   position.y = (screen_y/2)-(frameSize.y/2);

   sf::Vector2f screen_size;
   screen_size.x = screen_x;
   screen_size.y = screen_y;
   renderTexture.create(screen_x, screen_y);

   bullets = new Bullets(massCenter, screen_size, "c");

   collisionObject = new CollisionObject();
   collisionManager            = cManager;
   bullets->setCollisionManager(cManager);   

   collisionMargin.x = 22.f;
   collisionMargin.y = 10.f;

   collisionObject->type       = "c";  
   collisionObject->position   = position;
   collisionObject->position.x+= collisionMargin.x;
   collisionObject->position.y+= collisionMargin.y;
   collisionObject->size.x     = frameSize.x-collisionMargin.x*2;
   collisionObject->size.y     = frameSize.y-collisionMargin.y*2;
   collisionManager->include(collisionObject);

   controlTrigger = true;

   gunManager = new GunManager();
   gun1 = gunManager->getGun(2);
   activeGun = gun1; 
   gunFlag = 1;

   bullets->setLifetime(gun1.getRange());
   bullets->setDamage(gun1.getDamage());

   stamina = 30;
   bulletStock = 30;
}

void CharMain::changeSprite(float angle){
    if((angle>=0 && angle<32.195) || (angle>=328.8 && angle<=360)){
      sprite.setTextureRect(sf::IntRect(0, frameSize.y*2, 100, 100));
    }else if(angle>=32.195 && angle<152.276){
      sprite.setTextureRect(sf::IntRect(0, frameSize.y*1, 100, 100));
    }else if(angle>=152.276 && angle<206.8){
      sprite.setTextureRect(sf::IntRect(0, frameSize.y*3, 100, 100));
    }else if(angle>=206.8 && angle<328.8){
      sprite.setTextureRect(sf::IntRect(0, frameSize.y*4, 100, 100));
    }
}

void CharMain::update(float x, float y){
   gTime = gClock.getElapsedTime();
   gElapsed = gTime.asSeconds();

   bullets->moveBullets();
   
   float distance_x = x-massCenter.x;
   float distance_y = y-massCenter.y;

   float distance = sqrt(pow(distance_x, 2.0) + pow(distance_y,2.0));

   float s = distance_y/distance;
   float c = distance_x/distance;
   float ang = (atan2(s, c) * 180 / PI);

   if (ang < 0){
      ang += 360;
   }
   changeSprite(ang);

   if(hidden){
      sprite.setColor(sf::Color(255,255,255,190));
   }else{
      sprite.setColor(sf::Color(255,255,255,255));
   }

    for(unsigned i=0;i < collisionObject->events.size();i++){
      hp -= collisionObject->events[i];
      std::cout<<hp<<std::endl;
    }
    collisionObject->clearEvents();
}

void CharMain::move(sf::Vector2f pos){
   position.x = pos.x-(frameSize.x/2);
   position.y = pos.y-(frameSize.y/2);
   sprite.setPosition(position.x, position.y);
   collisionObject->position = position;
   collisionObject->position.x+= collisionMargin.x;
   collisionObject->position.y+= collisionMargin.y;
}

bool CharMain::testCollisionMovement(sf::Vector2f destination){
   std::string test = collisionManager->test(collisionObject, destination);
   if(test != "n"){
      if(test == "cs"){
         hidden = true;
         collisionObject->type = "h";
         return true;
      }else if(test == "ch" || test == "e"){
         return false;
      }
   }else{
      hidden = false;
      collisionObject->type = "c";
   }
   return true;
}

void CharMain::pushTrigger(sf::Vector2f dest){
   if(controlTrigger){
      if(activeGun.getRange() > 0){
         bullets->includeBullet(dest);
      }
      controlTrigger = false;
   }
   else{
      if(gElapsed >= (0.75/activeGun.getCadence())){
         gClock.restart();
         controlTrigger = true;
      }
   }
}

int CharMain::getTriggerType(){
   if (activeGun.getCadence() == 3){
      return 2;
   }else{
      return 1;
   }
}

bool CharMain::getHidden(){
   return hidden;
}

void CharMain::setHidden(bool h){
   hidden = h;
}

sf::Vector2f CharMain::getPosition(){
   return position;
}

float CharMain::getStamina(){
   return stamina;
}

int CharMain::getGunId(){
   return activeGun.getId();
}

int CharMain::getBulletQtd(){
   return bulletStock;
}