#ifndef STAGE1_HPP
#define STAGE1_HPP

#include <vector>
#include <SFML/System/Vector2.hpp>
#include <SFML/Graphics/Text.hpp>
#include <SFML/Graphics/Font.hpp>
#include <sstream>

#include "Display.hpp"
#include "SceneManager.hpp"
#include "CollisionManager.hpp"
#include "Input.hpp"
#include "CharMain.hpp"
#include "CharEnemmy.hpp"
#include "Hud.hpp"
#include "DropManager.hpp"
#include "DropStamina.hpp"
#include "WaveManager.hpp"

class Stage1 : public Scene { 
   Display * display;
   CharMain * farolete;

   WaveManager * waveManager;

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
   GameKey* c_key;
   GameKey* spacebar;
   GameKey* snapshot_key;

   MouseInput mouse;
   MouseButton* mb_left;
   MouseButton* mb_right;

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

   sf::Texture loadingTex;
   sf::Sprite  loadingSpr;

   float       loadWave;

   sf::Font    verdana;
   sf::Text    txtCont;
   int         cont;

public:
   Stage1(Display * d);

   void start();
   void draw();
   void render();
   void logic();
   void finish();
};

#endif