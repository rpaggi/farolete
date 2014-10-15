#include "Bullets.hpp"
#include <iostream>

#define PI 3.14159265


Bullets::Bullets(sf::Vector2f mass_center, sf::Vector2f screen_size, std::string own){
   owner = own;
   massCenter = mass_center;
   velocity = 5;

   texture.loadFromFile("images/bullet/texture.png");
   renderTexture.create(screen_size.x, screen_size.y);

   view = renderTexture.getView();

   elapsedCounter = 0;
   lifetime = 1.5;
}

void Bullets::destroyBullet(int i){
   position.erase(position.begin() + i);
   increment.erase(increment.begin() + i);
   destination.erase(destination.begin() + i);
   hidden.erase(hidden.begin() + i);
   elapsedTime.erase(elapsedTime.begin() + i);
               
   collisionManager->remove(collisionObject[i]);
   delete collisionObject[i];
   collisionObject.erase(collisionObject.begin() + i);
}

void Bullets::setCollisionManager(CollisionManager * cManager){
   collisionManager = cManager;
}

void Bullets::includeBullet(sf::Vector2f dest){
   time = clock.getElapsedTime();
   elapsed = time.asSeconds();

   //Calculate the increment
   float distance;
   sf::Vector2f aux;

   aux = dest-massCenter;
   distance = sqrt(pow(aux.x, 2.0) + pow(aux.y,2.0));

   increment.push_back(sf::Vector2f());
   increment[increment.size()-1].x = velocity * (aux.x/distance);
   increment[increment.size()-1].y = velocity * (aux.y/distance);

   position.push_back(sf::Vector2f());
   position[position.size()-1] = massCenter;

   destination.push_back(sf::Vector2f());
   destination[destination.size()-1] = dest;

   hidden.push_back(false);
   elapsedTime.push_back(elapsed);

   CollisionObject * cObj = new CollisionObject();

   if(owner == "c")
      cObj->type = "fc";
   else if(owner == "e")
      cObj->type = "fe";

   if(owner == "c")
      cObj->position       = view.getCenter();
   else
      cObj->position       = massCenter;

   cObj->size.x         = 15;
   cObj->size.y         = 15;
   collisionObject.push_back(cObj);
}

void Bullets::moveBullets() {
   time = clock.getElapsedTime();
   elapsed = time.asSeconds();
   bool controlReturn = true;
   view = renderTexture.getView();

   if ((elapsed - elapsedCounter) > 0.005) {
      for(unsigned i=0;i<position.size();i++){
         if (increment[i].x < 0 && increment[i].y < 0) {
            if ((position[i].x + increment[i].x) <= destination[i].x && (position[i].y + increment[i].y) <= destination[i].y){
               controlReturn = false;
            }
         } else if (increment[i].x > 0 && increment[i].y < 0) {
            if ((position[i].x + increment[i].x) >= destination[i].x && (position[i].y + increment[i].y) <= destination[i].y){
               controlReturn = false;
            }
         } else if (increment[i].x < 0 && increment[i].y > 0) {
            if ((position[i].x + increment[i].x) <= destination[i].x && (position[i].y + increment[i].y) >= destination[i].y){
               controlReturn = false;
            }
         } else if (increment[i].x > 0 && increment[i].y > 0) {
            if ((position[i].x + increment[i].x) >= destination[i].x && (position[i].y + increment[i].y) >= destination[i].y){
               controlReturn = false;
            }
         }

         CollisionObject cObjT = collisionManager->testGetObject(collisionObject[i]);

         if ((controlReturn == true && cObjT.type != "ch")
         && ((elapsed - elapsedTime[i]) <= lifetime)
            ){
            if(cObjT.type=="e" && owner == "c"){
               collisionManager->includeEventToObject(damage, cObjT.id);
               destroyBullet(i);
            }
            
            if(cObjT.type=="c" && owner == "e"){
               collisionManager->includeEventToObject(damage, cObjT.id);
               destroyBullet(i);
            }

            if(cObjT.type=="cs"){
               hidden[i] = true;
            }else if(hidden[i]){
               hidden[i] = false;
            }
            position[i].x += increment[i].x;
            position[i].y += increment[i].y;
            collisionObject[i]->position.x += increment[i].x;
            collisionObject[i]->position.y += increment[i].y;
         } else {
            destroyBullet(i);
         }

         controlReturn = true;
      }
      elapsedCounter = elapsed;
   }
}

sf::Sprite Bullets::getSprite(){
   sf::Sprite sprTemp;
   sf::Vector2f viewMovement;
   
   sprTemp.setTexture(texture);
   renderTexture.clear(sf::Color(255,255,255,0));

   viewMovement.x = ((view.getCenter().x*2) - view.getSize().x)/2;
   viewMovement.y = ((view.getCenter().y*2) - view.getSize().y)/2;

   for(unsigned i=0;i<position.size();i++){
      if(hidden[i]){
         sprTemp.setColor(sf::Color(255,255,255,0));
      }else{
         sprTemp.setColor(sf::Color(255,255,255,255));
      }
      sprTemp.setPosition(position[i]+viewMovement);
      renderTexture.draw(sprTemp);
      renderTexture.display();
   }

   sprite.setTexture(renderTexture.getTexture());
   sprite.setPosition(viewMovement);
   
   return sprite;
}

void Bullets::setView(sf::View view){
   renderTexture.setView(view);
}

void Bullets::setMassCenter(sf::Vector2f mc){
   massCenter = mc;
}

void Bullets::setLifetime(float l){
   lifetime = 0.4 * l;
}

void Bullets::setDamage(int d){
   damage = 2.5*(d+1);
}