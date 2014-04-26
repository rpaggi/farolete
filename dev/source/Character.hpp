#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include <SFML/System/Vector2.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <vector>
#include <cmath>

#define PI 3.14159265

class Character{
   sf::Vector2u massCenter;
   sf::Texture texture;
   sf::Sprite sprite;
   sf::Vector2u frameSize;

   void changeSprite(float angle);

 public:
   Character(float screen_x, float screen_y);

   void calculateAngle(float x, float y);

   sf::Sprite getSprite();

   void setPosition(sf::Vector2f position);

};

#endif