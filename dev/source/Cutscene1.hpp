#ifndef CUTSCENE1_HPP
#define CUTSCENE1_HPP

#include "Display.hpp"
#include "SceneManager.hpp"
#include "Input.hpp"

#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/System/Clock.hpp>
#include <SFML/System/Time.hpp>
#include <SFML/Audio.hpp>

class Cutscene1:public Scene{
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

	sf::Texture        texSeqC;
	sf::Sprite         sprSeqC;

	sf::Texture        texSeqD;
	sf::Sprite         sprSeqD;
	
	int                momento;

	sf::SoundBuffer    bufferBg;
	sf::Sound          soundBg;

	Scene            * goScene;

	void trataSprite(int function, sf::Sprite * sprite, float time);
public:
	Cutscene1(Display * display);
	void start();
	void draw();
	void render();
	void logic();
	void finish();
};

#endif