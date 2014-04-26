#include  "Stage1.hpp"

Stage1::Stage1(Display * d){
   display = d;
}

void Stage1::start(){
   float screen_x = display->getSize().x;
   float screen_y = display->getSize().y;

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
   view = display->getView();
//   mouse_position.x = (view.getCenter().x - view.getSize().x/2) + mouse_position.x;
//   mouse_position.y = (view.getCenter().y - view.getSize().y/2) + mouse_position.y;

   character->calculateAngle(mouse_position.x, mouse_position.y);
   character->setPosition(view.getCenter());
}

void Stage1::finish(){

}