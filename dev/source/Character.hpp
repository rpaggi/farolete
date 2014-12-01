#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include <SFML/System/Vector2.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Audio/Sound.hpp>
#include <SFML/Audio/SoundBuffer.hpp>
#include <vector>
#include <cmath>

#include "Display.hpp"
#include "Gun.hpp"
#include "Bullets.hpp"
#include "CollisionObject.hpp"
#include "CollisionManager.hpp"
#include "SpriteManager.hpp"

#define PI 3.14159265

class Character{
 protected:
   Character();
   Display *         display;
   sf::Vector2f      massCenter;
   sf::Texture       texture;
   sf::Sprite        sprite;
   sf::Vector2u      frameSize;
   sf::Vector2f      position;
   
   CollisionManager* collisionManager;
   CollisionObject * collisionObject;
   sf::Vector2f      collisionMargin;

   SpriteManager   * spriteManager;

   Bullets *         bullets;

   int               hp;
   int               xp;
   float             velocity;

   Gun               gun1;
   sf::Sound       * gunAudio;
   sf::SoundBuffer   gunBuffer;
   sf::Sound         walkSound;
   sf::SoundBuffer   walkBuffer;
   sf::Sound         deadSound;
   sf::SoundBuffer   deadBuffer;

   int               side;

 public:
   void draw();

   void setView(sf::View view);

   int  getHp();

   void animate();

   int getXp();
   void addXp(int xp);
};

#endif