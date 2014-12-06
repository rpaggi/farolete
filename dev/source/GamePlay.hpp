#ifndef GAMEPLAY_HPP
#define GAMEPLAY_HPP

#include <vector>
#include <SFML/System/Vector2.hpp>
#include <SFML/Graphics/Text.hpp>
#include <SFML/Graphics/Font.hpp>
#include <SFML/Audio/Music.hpp>
#include <SFML/Audio/SoundBuffer.hpp>
#include <SFML/Audio/Sound.hpp>
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
#include "LoaderImages.hpp"
#include "SaveGame.hpp"

class GamePlay : public Scene { 
protected:
   SaveGame    saveGame;
   Display   * display;
   CharMain  * farolete;

   sf::Music musicBg;
   sf::SoundBuffer bufferLoadWave;
   sf::Sound       soundLoadWave;

   WaveManager * waveManager;

   std::vector<CharEnemmy *> inimigos;

   KeyboardInput keyboard;
   GameKey* end;
   GameKey* home;
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

   sf::Texture savingTex;
   sf::Sprite  savingSpr;

   float       loadWave;

   sf::Font    verdana;
   sf::Text    txtCont;
   int         cont;

   bool        faroleteKill;
   bool        saving;

   int         fase;
   float       counter;
   Scene     * goScene;

public:
   GamePlay();

   void start();
   void draw();
   void render();
   void logic();
   void finish();
};

#endif