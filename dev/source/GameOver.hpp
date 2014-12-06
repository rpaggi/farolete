#ifndef GAMEOVER_HPP
#define GAMEOVER_HPP

#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/System/Clock.hpp>
#include <SFML/System/Time.hpp>
#include <SFML/Audio/SoundBuffer.hpp>
#include <SFML/Audio/Sound.hpp>

#include "Display.hpp"
#include "Input.hpp"
#include "SceneManager.hpp"
#include "SaveGame.hpp"
 
class GameOver : public Scene {
private:
	Display * display;

	KeyboardInput keyboard;
	GameKey* a_key;
	GameKey* d_key;
	GameKey* enter;
	GameKey* end;

	int      moment;
	int      selected;

	sf::Texture texBg;
	sf::Sprite  sprBg;

	sf::Texture texBtnContinue;
	sf::Sprite  sprBtnContinue;

	sf::Texture texBtnExit;
	sf::Sprite  sprBtnExit;

    sf::SoundBuffer buffMenu;
    sf::Sound       soundMenu;

	sf::Clock clock;
	float     elapsed;

	float     alpha;

	sf::RectangleShape blackScreen;

	Scene * goScene;

public:
	GameOver(Display * dis);

    void start();
    void draw();
    void render();
    void logic();
    void finish();
};

#endif