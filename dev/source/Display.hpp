#ifndef DISPLAY_HPP
#define DISPLAY_HPP

#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Text.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window/Event.hpp>
#include <SFML/System/Vector2.hpp>

#include <MapLoader.h>

class Display{
    sf::RenderWindow window;
public:
    Display();

    void handleEvents();

    bool isOpen();

    sf::Vector2u getSize();

    void display();

    const sf::View & getView();

    void setView(sf::View view);

    void draw(sf::Sprite sprite);

    void draw(sf::Text text);

    void draw(tmx::MapLoader* map);

    void clear(sf::Color color);

    bool pollEvent(sf::Event e);

    sf::Vector2i getMousePosition();
};

#endif
