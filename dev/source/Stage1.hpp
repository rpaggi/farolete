#ifndef STAGE1_HPP
#define STAGE1_HPP

#include <SFML/System/Vector2.hpp>

#include "Display.hpp"
#include "SceneManager.hpp"
#include "AssetsManager.hpp"
#include "Input.hpp"
#include "Character.hpp"

class Stage1 : public Scene {	
	Display * display;
	Character * character;

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
    float    mouseControl;

    sf::Vector2i mouse_position;
    sf::View view;

    tmx::MapLoader* mapLoader;
    sf::Vector2f screenMovement;

    sf::Clock clock;
    sf::Time time;
    float elapsed;

public:
	Stage1(Display * d);

	void start();
	void draw();
	void render();
	void logic();
	void finish();
};

#endif