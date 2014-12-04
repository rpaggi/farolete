#include "SceneSplash1.hpp"
#include "MainMenu.hpp"

SceneSplash1::SceneSplash1(Display * d) {
    display = d;
}

void SceneSplash1::start() {
    winSize = display->getSize();
    texSplash1.loadFromFile("images/splash1.png");
    sprSplash1.setTexture(texSplash1);
    float tX = texSplash1.getSize().x;
    float tY = texSplash1.getSize().y;
    sprSplash1.setPosition(winSize.x/2-tX/2,winSize.y/2-tY/2);
    relogio.restart();
    alpha1=0;
    alpha2=255;
    moment=1;
    goScene  = new MainMenu(display);
}

void SceneSplash1::draw() {
    display->clear(sf::Color(alpha2,alpha2,alpha2,255));
    sprSplash1.setColor(sf::Color(255,255,255,alpha1));
    display->draw(sprSplash1);
    
}

void SceneSplash1::render() {
    display->display();
}

void SceneSplash1::logic() {
    tempo = relogio.getElapsedTime();
    elapsed = tempo.asSeconds();
    switch(moment) {
    case 1:
        if(elapsed>0.75) {
            relogio.restart();
            alpha1 = 255;
            moment = 2;
        } else {
            alpha1 = elapsed * 340;
        }
        break;
    case 2:
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
            elapsed = 3.51;

        if(elapsed > 3.5) {
            relogio.restart();
            moment = 3;
        }
        break;
    case 3:
        if(alpha1 > 0) {
            alpha1 = (0.75-elapsed) * 255;
            alpha2 = alpha1;
        }else
            sceneManager->setCurrentScene(goScene);
        break;
    }
}

void SceneSplash1::finish() {}