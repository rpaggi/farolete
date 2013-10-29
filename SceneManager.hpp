#ifndef SCENEMANAGER_HPP
#define SCENEMANAGER_HPP

#include "Display.hpp"
#include "Scene.hpp"

class Scene;

class SceneManager {
	Scene * scene;
public:
	Display * display;

	SceneManager();

	void setDisplay(Display * d);

	void setCurrentScene(Scene * s);

	void run();

	bool isScene(Scene * s);

	void exit();

};

#endif