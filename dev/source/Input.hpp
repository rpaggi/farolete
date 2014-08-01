#ifndef INPUT_HPP
#define INPUT_HPP

#include <SFML/Window/Keyboard.hpp>
#include <SFML/Window/Mouse.hpp>


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

class MouseButton{
private:

public:
	sf::Mouse::Button button;
	bool pressed;
	MouseButton(sf::Mouse::Button b);
};

class MouseInput{
public:
	MouseInput();

	bool pressed(MouseButton &mouseButton);

	bool triggered(MouseButton &mouseButton);
};

#endif
