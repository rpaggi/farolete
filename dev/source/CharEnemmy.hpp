#ifndef CHARENEMMY_HPP
#define CHARENEMMY_HPP

#include "Display.hpp"
#include "Random.hpp"
#include "Character.hpp"
#include "CollisionManager.hpp"
#include "GunManager.hpp"
#include "DropManager.hpp"
#include <string>
#include <MapLoader.h>
#include <SFML/System/Time.hpp>
#include <SFML/System/Vector2.hpp>
#include <SFML/Graphics/RectangleShape.hpp>

class CharEnemmy : public Character {
private:
   //
   int id;
   //Direction code is the number of direction to the movimentation. Left=1, Up=2, Right=3 and Down=4
   int codDirection;
   int oldCodDirection;
   int alcanceVisao; 
   int pVc[4];
   float velocity;
   CollisionObject * visionX;
   CollisionObject * visionY;

   DropManager     * dropManager;

   sf::Vector2f      collisionMarginVision;

   bool              follow_flag;
   sf::Vector2f      follow_dest;
   int               follow_side;

   bool              hited;
   int               color;

    sf::Clock         clock;
    sf::Time          time;
    float             elapsed;

    GunManager *      gunManager;
    sf::Clock         gunClock;
    float             gunElapsed;

    Display *         display;

    bool              dropGun;

   void readSpawnAreas(tmx::MapLoader * mapLoader);

   void pushTrigger(sf::Vector2f dest);
public:
   CharEnemmy(Display * dis, float screen_x, float screen_y, CollisionManager * cManager, tmx::MapLoader * mapLoader, int hp, int xp, int gunId, float velocity, int idInimigo, float alcanceVisao);
   ~CharEnemmy();

   void update();

   bool testVision();

   bool getFollow();

   void draw();

   void follow(sf::Vector2f dest);

   void activeCollision();

   void kill();

   void setDropManager(DropManager *);

   void setDropGun(bool dg);
};

#endif