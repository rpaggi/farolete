#include  "Stage1.hpp"
#include <iostream>

Stage1::Stage1(Display * d){
   display = d;
}

void Stage1::start(){
   mouseControl = 0;

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

   collisionManager = new CollisionManager();

   farolete = new CharMain(screen_x, screen_y);
   farolete->setCollisionManager(collisionManager);

   mapLoader = new tmx::MapLoader("maps/map1/");
   mapLoader->Load("map1.tmx");
   collisionManager->include(mapLoader);

   sf::Vector2u mapSize = mapLoader->GetMapSize();
   mapSize.x = (mapSize.x/2)-(view.getSize().x/2);
   mapSize.y = (mapSize.y/2)-(view.getSize().y/2);
   view.move(mapSize.x, mapSize.y+30);
}

void Stage1::draw(){
   display->clear(sf::Color(0,0,0,255));
   display->draw(mapLoader);
   display->draw(farolete->getSprite());
   }

void Stage1::render(){
   display->display();
}

void Stage1::logic(){
   time = clock.getElapsedTime();
   elapsed = time.asSeconds();

   screenMovement.x = 0.f;
   screenMovement.y = 0.f;

   if (keyboard.triggered(*esc))
      sceneManager->exit();
   else if (keyboard.pressed(*up)||keyboard.pressed(*w_key))
      screenMovement.y = -0.1f;
   else if (keyboard.pressed(*down)||keyboard.pressed(*s_key))
      screenMovement.y = 0.1f;
   else if (keyboard.pressed(*left)||keyboard.pressed(*a_key))
      screenMovement.x = -0.1f;
   else if (keyboard.pressed(*right)||keyboard.pressed(*d_key))
      screenMovement.x = 0.1f;

   screenMovement = Helpers::Vectors::Normalize(screenMovement);

   if(!farolete->testCollisionMovement(screenMovement)){
      screenMovement.x = 0.f;
      screenMovement.y = 0.f;      
      screenMovement = Helpers::Vectors::Normalize(screenMovement);
   }

   mouse_position = display->getMousePosition();

   view.move(screenMovement);
   display->setView(view);
   farolete->update(mouse_position.x, mouse_position.y);
   farolete->move(view.getCenter());
   farolete->setView(view);

   if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && mouseControl < 1){
      mouseControl++;
      clock.restart();
      sf::Vector2f cast;
      cast.x = mouse_position.x;
      cast.y = mouse_position.y;
      farolete->pushTrigger(cast);   
   }

   if(mouseControl > 0 && elapsed > 0.3){
      clock.restart();
      mouseControl--;
    }
}

void Stage1::finish(){

}