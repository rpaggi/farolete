#include "MainMenu.hpp"
#include "Stage1.hpp"

MainMenu::MainMenu(Display * d) {
    display = d;
}

void MainMenu::start() {
    display->setShowMousePointer(false);

    sf::View view(sf::FloatRect(0,0,display->getSize().x, display->getSize().y));
    display->setView(view);

    w_key = new GameKey(sf::Keyboard::W);
    s_key = new GameKey(sf::Keyboard::S);
    enter = new GameKey(sf::Keyboard::Return);
    end = new GameKey(sf::Keyboard::End);

    option=1;

    buffMenu.loadFromFile("audio/menu.wav");
    soundMenu.setBuffer(buffMenu);
    soundMenu.setVolume(15);

    buffCapsule.loadFromFile("audio/capsule.wav");
    soundCapsule.setBuffer(buffCapsule);
    soundCapsule.setVolume(25);

    texBG.loadFromFile("images/mainmenu/background.png");
    sprBG.setTexture(texBG);

    texBtnNewGame.loadFromFile("images/mainmenu/btnNovoJogo.png");
    sprBtnNewGame.setTexture(texBtnNewGame);
    sprBtnNewGame.setTextureRect(sf::IntRect(0, 0, texBtnNewGame.getSize().x, texBtnNewGame.getSize().y/2));
    sprBtnNewGame.setPosition(295,283);

    texBtnContinue.loadFromFile("images/mainmenu/btnContinuar.png");
    sprBtnContinue.setTexture(texBtnContinue);
    sprBtnContinue.setTextureRect(sf::IntRect(0, 0, texBtnContinue.getSize().x, texBtnContinue.getSize().y/2));
    sprBtnContinue.setPosition(295,382);

    texBtnExit.loadFromFile("images/mainmenu/btnSair.png");
    sprBtnExit.setTexture(texBtnExit);
    sprBtnExit.setTextureRect(sf::IntRect(0, 0, texBtnExit.getSize().x, texBtnExit.getSize().y/2));
    sprBtnExit.setPosition(295,451);

    savegame.loadGame();
    if(savegame.stage>0){
        continueEnabled = true;
    }else{
        continueEnabled = false;
    }
}

void MainMenu::draw() {
    display->clear(sf::Color::Black);

    display->draw(sprBG);
    display->draw(sprBtnNewGame);
    if(continueEnabled) display->draw(sprBtnContinue);
    display->draw(sprBtnExit);
}
void MainMenu::render() {
    display->display();
}
void MainMenu::logic() {
    if (keyboard.triggered(*w_key)) {
        if(option>1){
            if(option == 3 && !continueEnabled){
                option = 1;
            }else{
                option--;
            }
        }
        soundMenu.play();
    }
    if (keyboard.triggered(*s_key)){
        if(option<3){
            if(option == 1 && !continueEnabled){
                option= 3;
            }else{
                option ++;
            }
        }
        soundMenu.play();
    }
    if (keyboard.triggered(*enter)){
        soundCapsule.play();
        switch (option){
            case 1:
                goScene  = new Stage1(display);
                sceneManager->setCurrentScene(goScene);
            break;

            case 2:
                goScene  = new Stage1(display, savegame);
                sceneManager->setCurrentScene(goScene);
            break;

            case 3:
                sceneManager->exit();
            break;
        }
    }
    // if (keyboard.triggered(*end)){
    //     sceneManager->exit();
    // }
    // if (not display->isOpen()){
    //     sceneManager->exit();
    // }

    switch (option){
        case 1:
        sprBtnNewGame.setTextureRect(sf::IntRect(0, texBtnNewGame.getSize().y/2, texBtnNewGame.getSize().x, texBtnNewGame.getSize().y/2));
        sprBtnContinue.setTextureRect(sf::IntRect(0, 0, texBtnContinue.getSize().x, texBtnContinue.getSize().y/2));
        sprBtnExit.setTextureRect(sf::IntRect(0, 0, texBtnExit.getSize().x, texBtnExit.getSize().y/2));
        break;

        case 2:
        sprBtnNewGame.setTextureRect(sf::IntRect(0, 0, texBtnNewGame.getSize().x, texBtnNewGame.getSize().y/2));
        sprBtnContinue.setTextureRect(sf::IntRect(0, texBtnContinue.getSize().y/2, texBtnContinue.getSize().x, texBtnContinue.getSize().y/2));
        sprBtnExit.setTextureRect(sf::IntRect(0, 0, texBtnExit.getSize().x, texBtnExit.getSize().y/2));
        break;

        case 3:
        sprBtnNewGame.setTextureRect(sf::IntRect(0, 0, texBtnNewGame.getSize().x, texBtnNewGame.getSize().y/2));
        sprBtnContinue.setTextureRect(sf::IntRect(0, 0, texBtnContinue.getSize().x, texBtnContinue.getSize().y/2));
        sprBtnExit.setTextureRect(sf::IntRect(0, texBtnExit.getSize().y/2, texBtnExit.getSize().x, texBtnExit.getSize().y/2));
        break;
    }
}
void MainMenu::finish() {
    delete this;
}
