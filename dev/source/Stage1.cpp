#include  "Stage1.hpp"
#include <iostream>

Stage1::Stage1(Display * d){
   display = d;
}

void Stage1::start(){
   float screen_x = display->getSize().x;
   float screen_y = display->getSize().y;

   view = display->getView();

   esc =   new GameKey(sf::Keyboard::Escape);
   up =    new GameKey(sf::Keyboard::Up);
   down =  new GameKey(sf::Keyboard::Down);
   left =  new GameKey(sf::Keyboard::Left);
   right = new GameKey(sf::Keyboard::Right);
   a_key = new GameKey(sf::Keyboard::A);
   s_key = new GameKey(sf::Keyboard::S);
   d_key = new GameKey(sf::Keyboard::D);
   w_key = new GameKey(sf::Keyboard::W);
   snapshot_key = new GameKey(sf::Keyboard::F12);

   mb_left = new MouseButton(sf::Mouse::Left);

   collisionManager = new CollisionManager();

   mapLoader = new tmx::MapLoader("maps/map1/");
   mapLoader->Load("map1.tmx");
   sf::Vector2u mapSize = mapLoader->GetMapSize();
   collisionManager->include(mapLoader);

   farolete = new CharMain(screen_x, screen_y, collisionManager);
   inimigoT = new CharEnemmy(screen_x, screen_y, collisionManager, mapLoader);

   mapSize.x = (mapSize.x/2)-(view.getSize().x/2);
   mapSize.y = (mapSize.y/2)-(view.getSize().y/2);
   view.move(mapSize.x, mapSize.y+30);

   hud = new Hud(display);
}

void Stage1::draw(){
   display->clear(sf::Color(0,0,0,255));
   display->draw(mapLoader);
   display->draw(farolete->getSprite());

   if (inimigoT->getHp() > 0)
      display->draw(inimigoT->getSprite());

   hud->draw();
}

void Stage1::render(){
   display->display();
}

void Stage1::logic(){
   time = clock.getElapsedTime();
   elapsed = time.asSeconds();

   screenMovement.x = 0.f;
   screenMovement.y = 0.f;

   sf::Vector2f iMovement;

   float vel = 1.7f;
   if (keyboard.triggered(*esc))
      sceneManager->exit();
   else if (keyboard.pressed(*w_key))
      screenMovement.y = -vel;
   else if (keyboard.pressed(*s_key))
      screenMovement.y = vel;
   else if (keyboard.pressed(*a_key))
      screenMovement.x = -vel;
   else if (keyboard.pressed(*d_key))
      screenMovement.x = vel;
   else if (keyboard.pressed(*snapshot_key))
      display->printScreen();

   //screenMovement = Helpers::Vectors::Normalize(screenMovement);

   if(!farolete->testCollisionMovement(screenMovement)){
      screenMovement.x = 0.f;
      screenMovement.y = 0.f;      
      screenMovement = Helpers::Vectors::Normalize(screenMovement);
   }

   mouse_position = display->getMousePosition();

   if(farolete->getHp() > 0){
      view.move(screenMovement);
      display->setView(view);
      farolete->move(view.getCenter());
      farolete->setView(view);

      if(farolete->getTriggerType() == 1){
         if (mouse.triggered(*mb_left)){
            sf::Vector2f cast;
            cast.x = mouse_position.x;
            cast.y = mouse_position.y;
            farolete->pushTrigger(cast);   
         }
      }else{
         if (mouse.pressed(*mb_left)){
            sf::Vector2f cast;
            cast.x = mouse_position.x;
            cast.y = mouse_position.y;
            farolete->pushTrigger(cast);   
         }
      }
   }else{
      farolete->setHidden(true);
   }

   farolete->update(mouse_position.x, mouse_position.y);
   hud->update(farolete->getHp(), farolete->getStamina(), farolete->getGunId(), farolete->getBulletQtd());

   if (inimigoT->getHp() > 0)
      inimigoT->update();


   if((inimigoT->testVision() && !farolete->getHidden())
   ||  inimigoT->getFollow()  && !farolete->getHidden()){
      inimigoT->follow(view.getCenter());
   }else{
      inimigoT->follow(sf::Vector2f(-1,-1));
   }

}

void Stage1::finish(){

}