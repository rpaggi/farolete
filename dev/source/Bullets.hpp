#ifndef BULLETS_HPP
#define BULLETS_HPP

//#include <math.h>
#include <cmath>
#include <vector>
#include <string>
#include <SFML/Graphics/RenderTexture.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/System/Vector2.hpp>
#include <SFML/System/Clock.hpp>
#include <SFML/System/Time.hpp>

#include "CollisionManager.hpp"
#include "Display.hpp"

class Bullets{
   std::vector<sf::Vector2f>     position;
   std::vector<sf::Vector2f>     destination;
   std::vector<sf::Vector2f>     increment;
   std::vector<bool>             hidden;
   std::vector<CollisionObject*> collisionObject;
   std::vector<float>            elapsedTime;
   CollisionManager *            collisionManager;
   sf::Vector2f                  massCenter;
   float                         velocity;
   sf::Texture                   texture;
   sf::Sprite                    sprite;
   sf::RenderTexture             renderTexture;
   Display *                     display;
   sf::View                      view;
    sf::Clock                     clock;
   sf::Time                      time;
   float                         elapsed;
   float                         elapsedCounter;
   std::string                   owner;
   float                         lifetime;
   float                         damage;

   bool                          hide;

   void                          destroyBullet(int i);
public:
   Bullets(sf::Vector2f mass_center, sf::Vector2f screen_size, std::string own, Display * dis);

   void setCollisionManager(CollisionManager * cManager);

   void includeBullet(sf::Vector2f dest);

   void moveBullets();

   void draw();

   void setView(sf::View view);

   void setMassCenter(sf::Vector2f mc);

   void setLifetime(float l);

   void setDamage(int d);

   void setHide(bool h);
};

#endif