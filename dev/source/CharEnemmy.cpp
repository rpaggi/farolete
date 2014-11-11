#include "CharEnemmy.hpp"
#include <iostream>
bool showCollisions = false;

CharEnemmy::CharEnemmy(Display * dis, float screen_x, float screen_y, CollisionManager * cManager, tmx::MapLoader * mapLoader){
   //Load the texture map
   texture.loadFromFile("images/character/cabra.png");
   sprite.setTexture(texture);
   frameSize.x = 102;
   frameSize.y = 104;

   display = dis;

   //Initialize colision areas
   collisionObject             = new CollisionObject();
   visionX                     = new CollisionObject();
   visionY                     = new CollisionObject();
   collisionManager            = cManager;

   //Define character collision
   collisionMargin.x = -22.f;
   collisionMargin.y = -10.f;
   collisionObject->type = "e";  
   this->readSpawnAreas(mapLoader);
   collisionObject->position.x -= collisionMargin.x;
   collisionObject->position.y -= collisionMargin.y;
   collisionObject->size.x     = frameSize.x+(collisionMargin.x*2);
   collisionObject->size.y     = frameSize.y+(collisionMargin.y*2);

   position.x = collisionObject->position.x + collisionMargin.x;
   position.y = collisionObject->position.y + collisionMargin.y;

   //Define visionX collision
   collisionMarginVision.x = 50.f;
   visionX->type = "v";  
   visionX->position.x = position.x - collisionMarginVision.x;
   visionX->position.y = collisionObject->position.y;
   visionX->size.x     = frameSize.x+(collisionMarginVision.x*2);
   visionX->size.y     = collisionObject->size.y;

   //Define visionY collision
   collisionMarginVision.y = 50.f;
   visionY->type = "v";  
   visionY->position.x = collisionObject->position.x;
   visionY->position.y = position.y - collisionMarginVision.y;
   visionY->size.x     = collisionObject->size.x;
   visionY->size.y     = frameSize.y+(collisionMarginVision.y*2);

   //Include collision objects in collision manager
   collisionManager->include(visionY);
   collisionManager->include(visionX);
   collisionManager->include(collisionObject);

   // Configure sprite frame
   sprite.setTextureRect(sf::IntRect(0, 0, frameSize.x, frameSize.y));
   sprite.setPosition(position.x,position.y);

   codDirection = RandomInteger(1,4);
   std::cout<<codDirection<<std::endl;
   alcanceVisao = 1;

   sf::Vector2f massCenter;
   sf::Vector2f screen_size;
   massCenter.x = position.x+(frameSize.x/2);
   massCenter.y = position.y+(frameSize.y/2);
   screen_size.x = mapLoader->GetMapSize().x;
   screen_size.y = mapLoader->GetMapSize().y;
   bullets = new Bullets(massCenter, screen_size, "e", display);
   bullets->setCollisionManager(cManager);   

   hited = false;
   color = 250;
   follow_flag = false;
   follow_side = 1;
   velocity = 0.2f;

   gunManager = new GunManager();
   gun1 = gunManager->getGun(2);

   bullets->setLifetime(gun1.getRange());
   bullets->setDamage(gun1.getDamage());
}

void CharEnemmy::readSpawnAreas(tmx::MapLoader * mapLoader){
   for(auto layer = mapLoader->GetLayers().begin(); layer != mapLoader->GetLayers().end(); ++layer){
      if(layer->name == "Spawn"){
            int maxObjects = layer->objects.size();
            int randLayers = RandomInteger(1,maxObjects);;
            collisionObject->position = layer->objects[randLayers-1].GetPosition();
      }
   }
}

void CharEnemmy::update(){
   if(hp > 0){
      //Movimenta as balas
      bullets->moveBullets();
   
      //Pega o tempo do inimigo
      time = clock.getElapsedTime();
      elapsed = time.asSeconds();
   
      //Pega o tempo da arma
      time = gunClock.getElapsedTime();
      gunElapsed = time.asSeconds();
   
      sf::Vector2f movement(0,0);
   
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
        std::cout<<hp<<std::endl;
        hited = true;
      }
      collisionObject->clearEvents();
   
      std::string collisionTest = collisionManager->test(collisionObject, movement);
   
      if(collisionTest == "n" || collisionTest == "e"){
         position = position + movement;
         sprite.setPosition(position);
         collisionObject->position = collisionObject->position + movement;
         visionX->position = visionX->position + movement;
         visionY->position = visionY->position + movement;
         massCenter.x = position.x+(frameSize.x/2);
         massCenter.y = position.y+(frameSize.y/2);
         bullets->setMassCenter(massCenter);
      }
   
      if(!follow_flag){
        if((collisionTest != "n" && collisionTest != "e")|| elapsed > 10.f){
            clock.restart();
            int r = RandomInteger(1,4);
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
        }
      }else{
        if(follow_side == 1){
          if(follow_dest.x >= position.x){
            codDirection = 3;
          }else{
            codDirection = 1;            
          }
        }else{
          if(follow_dest.y >= position.y){
            codDirection = 4;
          }else{
            codDirection = 2;            
          }
        }
   
        pushTrigger(follow_dest);
   
        if(collisionTest == "n" || collisionTest == "c" || collisionTest == "e"){
          if(elapsed > 1.5f){
            clock.restart();
            if(follow_side == 1){
              follow_side = 2;
            }else{
              follow_side = 1;
            }
          }
        }else{
          if(elapsed > 1.49f){
            clock.restart();
            follow_flag = false;
            velocity = 0.2f;
          }
          if(follow_side == 1){
            follow_side = 2;
          }else{
            follow_side = 1;
          }
        }
      }
   }
}

void CharEnemmy::draw(){
   if(hp > 0){
      sf::Sprite spriteTemp;
   
      if(hited){
         color = 200;
         hited = false;
      }
      else{
         if(color<255)
            color+=1;
      }
      sprite.setColor(sf::Color(color,color,255,255));
   
      if(showCollisions){
         sf::RectangleShape coll1;
         sf::RectangleShape coll2;
         sf::RectangleShape coll3;
   
         coll1.setSize(collisionObject->size);
         coll1.setOutlineColor(sf::Color::Red);
         coll1.setOutlineThickness(2);
         coll1.setPosition(collisionObject->position);
         coll1.setFillColor(sf::Color(0,0,0,0));
   
         coll2.setSize(visionX->size);
         coll2.setOutlineColor(sf::Color::Blue);
         coll2.setOutlineThickness(2);
         coll2.setPosition(visionX->position);
         coll2.setFillColor(sf::Color(0,0,0,0));
   
         coll3.setSize(visionY->size);
         coll3.setOutlineColor(sf::Color::Green);
         coll3.setOutlineThickness(2);
         coll3.setPosition(visionY->position);
         coll3.setFillColor(sf::Color(0,0,0,0));
   
         display->draw(coll3);
         display->draw(coll2);
         display->draw(coll1);
      }else{
         display->draw(sprite);
         bullets->draw();
      }
   }
}

bool CharEnemmy::testVision(){
  if(collisionManager->testVision(visionX) != "n" ||
     collisionManager->testVision(visionY) != "n"){
    return true;
  }
  return false;
}

void CharEnemmy::follow(sf::Vector2f dest){
   if(dest.x>=0){
      follow_flag = true;
      follow_dest = dest;
      velocity = 0.4f;
   }else{
      follow_flag = false;
      velocity = 0.2f;
   }
}

bool CharEnemmy::getFollow(){
   return follow_flag;
}

void CharEnemmy::pushTrigger(sf::Vector2f dest){
   if(gunElapsed > (0.75/gun1.getCadence())){
      if(gun1.getRange() > 0){
         bullets->includeBullet(dest);
      }
      gunClock.restart();
   }
}