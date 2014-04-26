#include "MainMenu.hpp"

MainMenu::MainMenu(Display * d) {
    display = d;
    down = new GameKey(sf::Keyboard::Down);
    up = new GameKey(sf::Keyboard::Up);
    enter = new GameKey(sf::Keyboard::Return);
    esc = new GameKey(sf::Keyboard::Escape);
}

void MainMenu::start() {
    option=1;

    background.loadFromFile("images/menu/menu_bg.png");
    txtBtNewGame.loadFromFile("images/menu/btNewGame.png");
    txtBtContinue.loadFromFile("images/menu/btContinue.png");
    txtBtSetup.loadFromFile("images/menu/btSetup.png");

    sprBG.setTexture(background);
    sprBtNG.setTexture(txtBtNewGame);
    sprBtCo.setTexture(txtBtContinue);
    sprBtSe.setTexture(txtBtSetup);

    sprBtNG.setTextureRect(sf::IntRect(0, 0, txtBtNewGame.getSize().x, txtBtNewGame.getSize().y/2));
    sprBtCo.setTextureRect(sf::IntRect(0, 0, txtBtContinue.getSize().x, txtBtContinue.getSize().y/2));
    sprBtSe.setTextureRect(sf::IntRect(0, 0, txtBtSetup.getSize().x, txtBtSetup.getSize().y/2));

    sprBtNG.setPosition(67,200);
    sprBtCo.setPosition(67,270);
    sprBtSe.setPosition(67,340);
}

void MainMenu::draw() {
    display->clear(sf::Color::Black);

    switch(option){
        case 1:
        sprBtNG.setTextureRect(sf::IntRect(0, txtBtNewGame.getSize().y/2, txtBtNewGame.getSize().x, txtBtNewGame.getSize().y/2));
        sprBtCo.setTextureRect(sf::IntRect(0, 0, txtBtContinue.getSize().x, txtBtContinue.getSize().y/2));
        break;

        case 2:
        sprBtCo.setTextureRect(sf::IntRect(0, txtBtContinue.getSize().y/2, txtBtContinue.getSize().x, txtBtContinue.getSize().y/2));
        sprBtNG.setTextureRect(sf::IntRect(0, 0, txtBtNewGame.getSize().x, txtBtNewGame.getSize().y/2));
        sprBtSe.setTextureRect(sf::IntRect(0, 0, txtBtSetup.getSize().x, txtBtSetup.getSize().y/2));
        break;

        case 3:
        sprBtSe.setTextureRect(sf::IntRect(0, txtBtSetup.getSize().y/2, txtBtSetup.getSize().x, txtBtSetup.getSize().y/2));
        sprBtCo.setTextureRect(sf::IntRect(0,0, txtBtContinue.getSize().x, txtBtContinue.getSize().y/2));
        break;
    }

    display->draw(sprBG);
    display->draw(sprBtNG);
    display->draw(sprBtCo);
    display->draw(sprBtSe);
}
void MainMenu::render() {
    display->display();
}
void MainMenu::logic() {
    if (keyboard.triggered(*up)) {
        if(option>1){
            option--;
        }
    }
    if (keyboard.triggered(*down)){
        if(option<3){
            option++;
        }
    }
    if (keyboard.triggered(*enter)){
        switch (option){
            case 1:
                goScene  = new Stage1(display);
                sceneManager->setCurrentScene(goScene);
            break;
        }
    }
    if (keyboard.triggered(*esc)){
        sceneManager->exit();
    }
    if (not display->isOpen()){
        sceneManager->exit();
    }
}
void MainMenu::finish() {}
