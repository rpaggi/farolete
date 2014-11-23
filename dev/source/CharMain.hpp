#ifndef CHARMAIN_HPP
#define CHARMAIN_HPP

#include "Character.hpp"
#include "GunManager.hpp"
#include <string>

class CharMain : public Character { 
private:
   bool          hidden;
   bool          controlTrigger;
   float         stamina;

   void          changeSprite(float angle);

   GunManager *  gunManager;
   int           gunFlag;
   Gun           activeGun;
   Gun           gun2;
   sf::Clock     gClock;
   sf::Time      gTime;
   float         gElapsed;
   int           bulletStock;
   float         fastShot;
public:
   CharMain(float screen_x, float screen_y, CollisionManager * cManager, Display * dis);

   void         update(float x, float y);

   void         move(sf::Vector2f pos);
      
   bool         testCollisionMovement(sf::Vector2f destination);

   void         pushTrigger(sf::Vector2f dest);

   void         fastTrigger(sf::Vector2f dest);

   int          getTriggerType();

   bool         getHidden();
   
   void         setHidden(bool h);

   sf::Vector2f getPosition();

   float        getStamina();

   int          getGunId();

   int          getBulletQtd();

   void         switchGun();
};

#endif