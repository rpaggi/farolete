#include "Display.hpp"

Display::Display() {
    //window.create(sf::VideoMode(1024, 600), "xingu", sf::Style::Fullscreen);
    //Use window mode to dev the game (:
    window.create(sf::VideoMode(1024, 600), "xingu");
}

void Display::handleEvents() {
    sf::Event event;
    while (window.pollEvent(event)) {
        if (event.type == sf::Event::Closed)
            window.close();
    }
}

bool Display::isOpen() {
    return window.isOpen(); 
}

sf::Vector2u Display::getSize() {
    return window.getSize();
}

void Display::display() {
    window.display();
}

void Display::draw(sf::Sprite sprite) {
    window.draw(sprite);
}

void Display::draw(sf::Text text) {
    window.draw(text);
}

void Display::draw(tmx::MapLoader* map) {
    window.draw(*map);
}

void Display::clear(sf::Color color) {
    window.clear(color);
}

bool Display::pollEvent(sf::Event e) {
    return window.pollEvent(e);
}

sf::Vector2i Display::getMousePosition(){
    return sf::Mouse::getPosition(window);
}
