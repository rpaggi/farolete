#ifndef STAGE1_HPP
#define STAGE1_HPP

#include <vector>
#include <SFML/System/Vector2.hpp>

#include "Display.hpp"
#include "SceneManager.hpp"
#include "CollisionManager.hpp"
#include "Input.hpp"
#include "CharMain.hpp"
#include "CharEnemmy.hpp"
#include "Hud.hpp"
#include "DropManager.hpp"
#include "DropStamina.hpp"

class Stage1 : public Scene { 
   Display * display;
   CharMain * farolete;

   std::vector<CharEnemmy *> inimigos;

   KeyboardInput keyboard;
   GameKey* esc;
   GameKey* up;
   GameKey* down;
   GameKey* left;
   GameKey* right;
   GameKey* a_key;
   GameKey* s_key;
   GameKey* d_key;
   GameKey* w_key;
   GameKey* snapshot_key;

   MouseInput mouse;
   MouseButton* mb_left;

   sf::Vector2i mouse_position;
   sf::View view;

   tmx::MapLoader* mapLoader;
   sf::Vector2f screenMovement;

   sf::Clock clock;
   sf::Time time;
   float elapsed;

   CollisionManager * collisionManager;

   Hud * hud;

   DropItem    * dropStamina;
   DropManager * dropManager;

public:
   Stage1(Display * d);

   void start();
   void draw();
   void render();
   void logic();
   void finish();
};

#endif