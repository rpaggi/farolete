#ifndef SCENE_HPP
#define SCENE_HPP

#include "SceneManager.hpp"

class SceneManager;

class Scene {
protected:
	SceneManager * sceneManager;
public:
	void main(SceneManager* sm);

	virtual void start();

	virtual void update();

	virtual void draw();

	virtual void render();

	virtual void logic();

	virtual void finish();
};

#endif