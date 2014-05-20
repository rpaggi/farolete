#include "CharMain.hpp"

CharMain::CharMain(float screen_x, float screen_y){
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
  sprite.setTextureRect(sf::IntRect(0, 0, 100, 100));
  sprite.setPosition((screen_x/2)-frameSize.x,(screen_y/2)-frameSize.y);

  sf::Vector2f screen_size;
  screen_size.x = screen_x;
  screen_size.y = screen_y;
  renderTexture.create(screen_x, screen_y);
  bullets = new Bullets(massCenter, screen_size);
}