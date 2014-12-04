#ifndef MAINMENU_HPP
#define MAINMENU_HPP

#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>

#include "Display.hpp"
#include "Input.hpp"
#include "SceneManager.hpp"

class MainMenu : public Scene {
private:
    Display * display;
    sf::Texture background;
    sf::Texture txtBtNewGame;
    sf::Texture txtBtContinue;
    sf::Texture txtBtSetup;
    sf::Sprite sprBG;
    sf::Sprite sprBtNG;
    sf::Sprite sprBtCo;
    sf::Sprite sprBtSe;
    GameKey* down;
    GameKey* up;
    GameKey* enter;
    GameKey* esc;
    KeyboardInput keyboard;
    int option;
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
