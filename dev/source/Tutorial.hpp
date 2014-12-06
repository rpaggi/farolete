#ifndef TUTORIAL_HPP
#define TUTORIAL_HPP

#include "Display.hpp"
#include "SceneManager.hpp"
#include "Input.hpp"

#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/System/Clock.hpp>
#include <SFML/System/Time.hpp>

class Tutorial:public Scene{
private:
	Display *          display;
	sf::Clock          clock;
	float              elapsed;

	KeyboardInput keyboard;
	GameKey     * space;

	sf::Texture        texImg1;
	sf::Sprite         sprImg1;

	sf::Texture        texImg2;
	sf::Sprite         sprImg2;
	
	int                momento;

	Scene            * goScene;

	void trataSprite(int function, sf::Sprite * sprite, float time);
public:
	Tutorial(Display * display);
	void start();
	void draw();
	void render();
	void logic();
	void finish();
};

#endif