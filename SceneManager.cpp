#include "SceneManager.hpp"

SceneManager::SceneManager() {
    display = NULL;
    scene = NULL;
}

void SceneManager::setDisplay(Display * d) {
    display = d;
}

void SceneManager::setCurrentScene(Scene * s) {
    scene = s;
}

void SceneManager::run() {
    while (scene != NULL && display->isOpen()) {
        scene->main(this);
    }
}

bool SceneManager::isScene(Scene * s) {
    if(scene == s && display->isOpen())
        return true;
    return false;
}

void SceneManager::exit() {
    scene = NULL;
}
