#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include <SFML/System/Vector2.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <vector>
#include <cmath>

#include "Bullets.hpp"

#define PI 3.14159265

class Character{
 protected:
   Character();

   sf::Vector2f      massCenter;
   sf::Texture       texture;
   sf::RenderTexture renderTexture;
   sf::Sprite        sprite;
   sf::Vector2u      frameSize;
   sf::Vector2f      position;

   void              changeSprite(float angle);

   Bullets *         bullets;

   int               hp;
   int               xp;
   int               level;
   //Arma *          equipament;
   float             velocity;

 public:
   sf::Sprite getSprite();

   void move(sf::Vector2f position);

   void move(float x, float y);

   void setView(sf::View view);

   void pushTrigger(sf::Vector2f dest);

};

#endif