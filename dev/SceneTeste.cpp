#include "SceneTeste.hpp"

SceneTeste::SceneTeste(Display * d) {
    display = d;
}

void SceneTeste::start() {
    timer = 1024;
    texture.loadFromFile("teste.png");
    sprite.setTexture(texture);
    sprite.setPosition(200,200);
}
void SceneTeste::draw() {
    display->clear(sf::Color::Black);
    display->draw(sprite);
}
void SceneTeste::render() {
    display->display();
}
void SceneTeste::logic() {
    if (timer < 0 || not display->isOpen()) {
        sceneManager->exit();
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)
    ||  sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
        sceneManager->exit();
    timer -= 1;
}
void SceneTeste::finish() {}
