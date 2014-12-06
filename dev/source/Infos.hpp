#ifndef INFOS_HPP
#define INFOS_HPP

#include "Display.hpp"
#include "SceneManager.hpp"
#include "Input.hpp"

#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/System/Clock.hpp>
#include <SFML/System/Time.hpp>


class Infos:public Scene{
private:
	Display *          display;
	sf::Clock          clock;
	float              elapsed;

	KeyboardInput keyboard;
	GameKey     * esc;

	sf::Texture        texBg;
	sf::Sprite         sprBg;
	
	int                momento;

	Scene            * goScene;

	void trataSprite(int function, sf::Sprite * sprite, float time);
public:
	Infos(Display * display);
	void start();
	void draw();
	void render();
	void logic();
	void finish();
};

#endif