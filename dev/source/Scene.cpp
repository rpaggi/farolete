#include "Scene.hpp"
#include <iostream>

void Scene::main(SceneManager * sm) {
    sceneManager = sm;

    this->start();
    while(sm->isScene(this)){
        sm->display->handleEvents();
        this->update();
    }
    this->finish();
}

void Scene::start() {}

void Scene::update() {
    this->draw();
    this->render();
    this->logic();
}

void Scene::draw() {}

void Scene::render() {}

void Scene::logic() {}

void Scene::finish() {}