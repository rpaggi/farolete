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
}

void Stage1::draw(){
   display->clear(sf::Color(0,0,0,255));
   display->draw(mapLoader);
   display->draw(farolete->getSprite());

   if (inimigoT->getHp() > 0)
      display->draw(inimigoT->getSprite());
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

   if (keyboard.triggered(*esc))
      sceneManager->exit();
   else if (keyboard.pressed(*w_key))
      screenMovement.y = -0.1f;
   else if (keyboard.pressed(*s_key))
      screenMovement.y = 0.1f;
   else if (keyboard.pressed(*a_key))
      screenMovement.x = -0.1f;
   else if (keyboard.pressed(*d_key))
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

   if (inimigoT->getHp() > 0)
      inimigoT->update();

   if (mouse.triggered(*mb_left)){
      sf::Vector2f cast;
      cast.x = mouse_position.x;
      cast.y = mouse_position.y;
      farolete->pushTrigger(cast);   
   }

}

void Stage1::finish(){

}