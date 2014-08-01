#include "CharEnemmy.hpp"
#include <iostream>

CharEnemmy::CharEnemmy(float screen_x, float screen_y, CollisionManager * cManager, tmx::MapLoader * mapLoader){
   srand (std::time(NULL));
   hp = 100;  

   //Load the texture map
   texture.loadFromFile("images/character/character.png");
   sprite.setTexture(texture);
   frameSize.x = 100;
   frameSize.y = 100;

   collisionObject = new CollisionObject();
   collisionManager            = cManager;

   collisionMargin.x = -22.f;
   collisionMargin.y = -10.f;

   collisionObject->type       = "e";  
   this->readSpawnAreas(mapLoader);
   collisionObject->position.x -= collisionMargin.x;
   collisionObject->position.y -= collisionMargin.y;
   collisionObject->size.x     = frameSize.x+(collisionMargin.x*2);
   collisionObject->size.y     = frameSize.y+(collisionMargin.y*2);
   collisionManager->include(collisionObject);

   position.x = collisionObject->position.x + collisionMargin.x;
   position.y = collisionObject->position.y + collisionMargin.y;

   // Configure sprite frame
   sprite.setTextureRect(sf::IntRect(0, 0, frameSize.x, frameSize.y));
   sprite.setPosition(position.x,position.y);

   codDirection = rand() % 4 + 1;
   oldCodDirection = codDirection;
   std::cout<<codDirection<<std::endl;
   alcanceVisao = 1;

   sf::Vector2f massCenter;
   sf::Vector2f screen_size;
   massCenter.x = position.x+(frameSize.x/2);
   massCenter.y = position.y+(frameSize.y/2);
   screen_size.x = screen_x;
   screen_size.y = screen_y;
   bullets = new Bullets(massCenter, screen_size, "e");
   bullets->setCollisionManager(cManager);   

   hited = false;
   color = 200;
}

void CharEnemmy::readSpawnAreas(tmx::MapLoader * mapLoader){
   for(auto layer = mapLoader->GetLayers().begin(); layer != mapLoader->GetLayers().end(); ++layer){
      if(layer->name == "Spawn"){
            srand (std::time(NULL));
            int maxObjects = layer->objects.size();
            int randLayers = rand() % maxObjects + 1;
            collisionObject->position = layer->objects[randLayers-1].GetPosition();
      }
   }
}

void CharEnemmy::update(){
    time = clock.getElapsedTime();
    elapsed = time.asSeconds();
    sf::Vector2f movement(0,0);
    float velocity = 0.5f;

    if(codDirection == 3){
      sprite.setTextureRect(sf::IntRect(0, frameSize.y*2, 100, 100));
      movement.x += velocity;
    }else if(codDirection == 4){
      sprite.setTextureRect(sf::IntRect(0, frameSize.y*1, 100, 100));
      movement.y += velocity;
    }else if(codDirection == 1){
      sprite.setTextureRect(sf::IntRect(0, frameSize.y*3, 100, 100));
      movement.x -= velocity;
    }else if(codDirection == 2){
      sprite.setTextureRect(sf::IntRect(0, frameSize.y*4, 100, 100));
      movement.y -= velocity;
    }
   
    for(unsigned i=0;i < collisionObject->events.size();i++){
      hp -= collisionObject->events[i];
      hited = true;
    }
    collisionObject->clearEvents();

    std::string collisionTest = collisionManager->test(collisionObject, movement);
    if(collisionTest != "n" || elapsed > 5.f){
        clock.restart();
        srand (std::time(NULL));
        int r = rand() % 4 + 1;
        oldCodDirection = codDirection;
        if(codDirection == r){
            if(codDirection == 4){
                codDirection    = 1;
            }else{
                codDirection++;
            }
        }else{
            codDirection = r;
        }
    }else{
        position = position + movement;
        sprite.setPosition(position);
        collisionObject->position = collisionObject->position + movement;
    }
}

sf::Sprite CharEnemmy::getSprite(){
   if(hited){
      color = 150;
      hited = false;
   }
   else{
      if(color>100)
         color-=1;
   }
   sprite.setColor(sf::Color(255,100,color,255));

   return sprite;
}