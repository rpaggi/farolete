#ifndef INPUT_HPP
#define INPUT_HPP

#include <SFML/Window/Keyboard.hpp>


class GameKey {
private:
    
public:
    sf::Keyboard::Key key;
    bool pressed;
    GameKey(sf::Keyboard::Key k);
};

class KeyboardInput {
private:
    unsigned int deviceID;
public:
    KeyboardInput();

    bool pressed(GameKey &gameKey);

    bool triggered(GameKey &gameKey);
};

#endif
