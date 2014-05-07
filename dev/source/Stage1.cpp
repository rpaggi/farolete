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

   esc = new GameKey(sf::Keyboard::Escape);
   up = new GameKey(sf::Keyboard::Up);
   down = new GameKey(sf::Keyboard::Down);
   left = new GameKey(sf::Keyboard::Left);
   right = new GameKey(sf::Keyboard::Right);

   character = new Character(screen_x, screen_y);

   mapLoader = new tmx::MapLoader("maps/");
   mapLoader->Load("desert.tmx");
}

void Stage1::draw(){
   display->clear(sf::Color(255,255,255,255));
   display->draw(mapLoader);
   display->draw(character->getSprite());
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
   if (keyboard.pressed(*up))
      screenMovement.y = -0.1f;
   if (keyboard.pressed(*down))
      screenMovement.y = 0.1f;
   if (keyboard.pressed(*left))
      screenMovement.x = -0.1f;
   if (keyboard.pressed(*right))
      screenMovement.x = 0.1f;

   screenMovement = Helpers::Vectors::Normalize(screenMovement) * 10.f;
   view.move(screenMovement);
   display->setView(view);

   mouse_position = display->getMousePosition();
   mouse_position.x = (view.getCenter().x - view.getSize().x/2) + mouse_position.x;
   mouse_position.y = (view.getCenter().y - view.getSize().y/2) + mouse_position.y;

   character->update(mouse_position.x, mouse_position.y);
   character->setPosition(view.getCenter());
   character->setView(view);


   // if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && mouseControl < 1)
   if (sf::Mouse::isButtonPressed(sf::Mouse::Left)){
      // mouseControl++;
      clock.restart();
      sf::Vector2f cast;
      cast.x = mouse_position.x;
      cast.y = mouse_position.y;
      character->pushTrigger(cast);   
   }

   // if(mouseControl > 0 && elapsed > 0.03){
   //    clock.restart();
   //    mouseControl--;
   //  }
}

void Stage1::finish(){

}