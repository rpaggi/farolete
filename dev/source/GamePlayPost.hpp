#ifndef GAMEPLAYPOST_HPP
#define GAMEPLAYPOST_HPP

#include "SceneManager.hpp"
#include "Display.hpp"

#include <SFML/System/Clock.hpp>

class GamePlayPost:public Scene{
private:
	Scene * goScene;
	sf::Clock clock;
	Display * display;

	int tela;
public:
	GamePlayPost(Display * d, int tela);

	void start();
	void logic();
};

#endif