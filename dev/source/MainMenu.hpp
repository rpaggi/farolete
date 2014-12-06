#ifndef MAINMENU_HPP
#define MAINMENU_HPP

#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Audio/SoundBuffer.hpp>
#include <SFML/Audio/Sound.hpp>

#include "Display.hpp"
#include "Input.hpp"
#include "SceneManager.hpp"
#include "SaveGame.hpp"

class MainMenu : public Scene {
private:
    Display * display;

    sf::Texture texBG;
    sf::Sprite  sprBG;

    sf::Texture texBtnNewGame;
    sf::Sprite  sprBtnNewGame;

    sf::Texture texBtnContinue;
    sf::Sprite  sprBtnContinue;

    sf::Texture texBtnExit;
    sf::Sprite  sprBtnExit;

    sf::Texture texBtnInfo;
    sf::Sprite  sprBtnInfo;

    KeyboardInput keyboard;
    GameKey* w_key;
    GameKey* s_key;
    GameKey* enter;
    GameKey* end;

    int option;

    SaveGame savegame;

    bool continueEnabled;

    sf::SoundBuffer buffMenu;
    sf::Sound       soundMenu;

    Scene * goScene;
public:
    MainMenu(Display * d);    

    void start();

    void draw();
    
    void render();

    void logic();

    void finish();

};

#endif
