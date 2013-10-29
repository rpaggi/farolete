#ifndef SCENETESTE_HPP
#define SCENETESTE_HPP

#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Window/Keyboard.hpp>


#include "Display.hpp"
#include "Input.hpp"
#include "SceneManager.hpp"
#include "MainMenu.hpp"

class SceneTeste:public Scene{
	Display * display;
	int timer;
	sf::Texture texture;
	sf::Sprite sprite;
public:
	SceneTeste(Display * d);

	void start();
	void draw();
	void render();
	void logic();
	void finish();
};

#endif
