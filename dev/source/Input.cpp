#include "Input.hpp"

GameKey::GameKey(sf::Keyboard::Key k) {
    key = k;
    pressed = false;
}

KeyboardInput::KeyboardInput() {}

bool KeyboardInput::pressed(GameKey &gameKey) {
    return sf::Keyboard::isKeyPressed(gameKey.key);
}

bool KeyboardInput::triggered(GameKey &gameKey) {
    bool now = sf::Keyboard::isKeyPressed(gameKey.key);
    bool * before = &gameKey.pressed;

    if (now && !*before) {
        *before = true;
        return true;
    } else if (!now && !*before) {
        *before = false;
        return false;
    } else if (!now && *before) {
        *before = false;
        return false;
    } else if (now && *before) {
        *before = true;
        return false;
    }
}

MouseButton::MouseButton(sf::Mouse::Button b) {
    button = b;
    pressed = false;
}

MouseInput::MouseInput() {}

bool MouseInput::pressed(MouseButton &mouseButton) {
    return sf::Mouse::isButtonPressed(mouseButton.button);
}

bool MouseInput::triggered(MouseButton &mouseButton) {
    bool now = sf::Mouse::isButtonPressed(mouseButton.button);
    bool * before = &mouseButton.pressed;

    if (now && !*before) {
        *before = true;
        return true;
    } else if (!now && !*before) {
        *before = false;
        return false;
    } else if (!now && *before) {
        *before = false;
        return false;
    } else if (now && *before) {
        *before = true;
        return false;
    }
}