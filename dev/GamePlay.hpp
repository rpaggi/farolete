#ifndef GAMEPLAY_HPP
#define GAMEPLAY_HPP

#include <math.h>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/System/Vector2.hpp>
#include <SFML/Window/Mouse.hpp>
#include <vector>

#include "Display.hpp"
#include "SceneManager.hpp"
#include "Input.hpp"
#include "Shot.hpp"


class GamePlay : public Scene {
	Display * display;

    KeyboardInput keyboard;
    GameKey* esc;
    GameKey* up;
    GameKey* down;
    GameKey* left;
    GameKey* right;
    int freeMouse;
    float timeShot;

    //time variables
    sf::Clock clock;
	sf::Time time;
	float elapsed;

    //person
    int pos;
    sf::Vector2u perCm;
    std::vector<sf::Texture> perText;
    std::vector<sf::Sprite> perSprite;

    //shot
    std::vector<Shot*> vShot;

    //map
    tmx::MapLoader* mapLoader;

    //camera view
    sf::Vector2f screenMovement;

    float angBetween(float cmX, float cmY, float pX, float pY);
public:
	GamePlay(Display * d);

	void start();
	void draw();
	void render();
	void logic();
	void finish();
};

#endif