#ifndef CUTSCENE2_HPP
#define CUTSCENE2_HPP

#include "Display.hpp"
#include "SceneManager.hpp"
#include "Input.hpp"
#include "SaveGame.hpp"

#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/System/Clock.hpp>
#include <SFML/System/Time.hpp>


class Cutscene2:public Scene{
private:
	Display *          display;
	sf::Clock          clock;
	float              elapsed;

	KeyboardInput keyboard;
	GameKey     * space;

	sf::Texture        texSeqA;
	sf::Sprite         sprSeqA;

	sf::Texture        texSeqB;
	sf::Sprite         sprSeqB;
	
	int                momento;

	SaveGame           savegame;

	Scene            * goScene;

	void trataSprite(int function, sf::Sprite * sprite, float time);
public:
	Cutscene2(Display * display);
	void start();
	void draw();
	void render();
	void logic();
	void finish();
};

#endif