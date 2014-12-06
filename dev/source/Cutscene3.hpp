#ifndef CUTSCENE3_HPP
#define CUTSCENE3_HPP

#include "Display.hpp"
#include "SceneManager.hpp"
#include "Input.hpp"

#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/System/Clock.hpp>
#include <SFML/System/Time.hpp>


class Cutscene3:public Scene{
private:
	Display *          display;
	sf::Clock          clock;
	float              elapsed;

	KeyboardInput keyboard;
	GameKey     * space;

	sf::Texture        texSeqA;
	sf::Sprite         sprSeqA;
	
	int                momento;

	Scene            * goScene;

	void trataSprite(int function, sf::Sprite * sprite, float time);
public:
	Cutscene3(Display * display);
	void start();
	void draw();
	void render();
	void logic();
	void finish();
};

#endif