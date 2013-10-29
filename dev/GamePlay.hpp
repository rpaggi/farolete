#ifndef GAMEPLAY_HPP
#define GAMEPLAY_HPP

#include <math.h>
#include <SFML/System/Vector2.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Window/Mouse.hpp>

#include "Display.hpp"
#include "SceneManager.hpp"
#include "Input.hpp"

class GamePlay : public Scene {
	Display * display;

    KeyboardInput keyboard;
    GameKey* esc;

    //personagem
    int pos;
    sf::Vector2u perCm;
    std::vector<sf::Texture> perText;
    std::vector<sf::Sprite> perSprite;

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