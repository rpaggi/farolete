#ifndef SCENESPLASH1_HPP
#define SCENESPLASH1_HPP

#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/System/Vector2.hpp>
#include <SFML/System/Clock.hpp>
#include <SFML/System/Time.hpp>

#include "Display.hpp"
#include "SceneManager.hpp"
#include "MainMenu.hpp"

class SceneSplash1 : public Scene {
	Display * display;
    sf::Sprite sprSplash1;
    sf::Texture texSplash1;
    sf::Vector2u winSize;
	sf::Clock relogio;
	sf::Time tempo;
	float elapsed;
	int alpha1;
	int alpha2;
	int moment;
	Scene * goScene;
public:
	SceneSplash1(Display * d);	
	void start();
	void draw();
	void render();
	void logic();
	void finish();
};

#endif
