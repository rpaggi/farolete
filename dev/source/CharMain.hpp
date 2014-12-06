#ifndef CHARMAIN_HPP
#define CHARMAIN_HPP

#include "Character.hpp"
#include "GunManager.hpp"
#include <string>

class CharMain : public Character { 
private:
   void          init(float screen_x, float screen_y, CollisionManager * cManager, Display * dis);
   void          changeSprite(float angle);
   
   bool          hidden;
   bool          controlTrigger;
   float         stamina;


   GunManager *  gunManager;
   int           gunFlag;
   Gun        *  activeGun;
   Gun           gun2;
   sf::Clock     gClock;
   sf::Time      gTime;
   float         gElapsed;
   int           bulletStock;
   float         fastShot;
   bool          godMode;
public:
   CharMain(float screen_x, float screen_y, CollisionManager * cManager, Display * dis);
   CharMain(float screen_x, float screen_y, CollisionManager * cManager, Display * dis, int h, int s, int x, int b, int g);

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

   int          getGunId(int id);

   int          getBulletQtd();

   void         switchGun();

   void         kill();

   void         switchGodMode();
};

#endif