#include "SpriteManager.hpp"
#include <iostream>

SpriteManager::SpriteManager(Display * d, std::string file){
   display = d;
   texture.loadFromFile(file);
   sprite.setTexture(texture);
   sprite.setTextureRect(sf::IntRect(0, 0, 100, 100));
   animationFrame = 0;
   frameRate = 0.15;
   color = 255;
   alpha = 255;
}

void SpriteManager::draw(){
   if(hited){
       color = 200;
       hited = false;
   }
   else{
       if(color<255)
            color+=1;
   }

   if(hide){
      alpha = 190;
   }else{
      alpha = 255;
   }

   sprite.setColor(sf::Color(color,color,255,alpha));

   display->draw(sprite);
}

void SpriteManager::update(int gunId, int side){
   float currentTime = clock.getElapsedTime().asSeconds();

   // sprite.setPosition(position);
   int gunCast;

   // gunId = 6;
   if(gunId < 6){
      if(gunId == 1){
         if(animateM)
            gunCast = 2;
         else
            gunCast = gunId;

      }else if(gunId == 2){
         gunCast = 4;
      }else if(gunId == 3){
         gunCast = 3;
      }else if(gunId == 4){
         gunCast = 5;
      }else if(gunId == 5){
         gunCast = 6;
      }
      sprite.setTextureRect(sf::IntRect((((100*3)*(side-1))+(100*animationFrame)), (100*gunCast), 100, 100));

      if(currentTime > 0.05 && animateM){
         animationFrame += 1;
         if(animationFrame>2){
            animationFrame = 0;
            animateM = false;  
         }

         clock.restart();
      }
      // sprite.setTextureRect(sf::IntRect((((100*3)*(side-1))+(100*animationFrame)), 600, 100, 100));
   }else{
      if(side == 1){
         sprite.setTextureRect(sf::IntRect(0, 700, 100, 120));
      }else if(side == 2){
         sprite.setTextureRect(sf::IntRect(300, 700, 100, 139));
      }else if(side == 3){
         sprite.setTextureRect(sf::IntRect(600, 700, 156, 100));
      }else if(side == 4){
         sprite.setTextureRect(sf::IntRect(1000, 700, 156, 100));
      }
   }

}

void SpriteManager::setPosition(sf::Vector2f position){
   sprite.setPosition(position);
}

void SpriteManager::setHide(bool hide){
   this->hide = hide;
}

void SpriteManager::animate(){
   float currentTime = clock.getElapsedTime().asSeconds();

   if(currentTime > frameRate && !animateM){
      animationFrame += 1;
      if(animationFrame>2){
         animationFrame = 0;  
      }

      clock.restart();
   }
}

void SpriteManager::animateMachete(){
   animateM = true;
   animationFrame = 0;
}

void SpriteManager::hit(){
   hited = true;
}

void SpriteManager::setFrameRate(float fr){
   frameRate = fr;
}