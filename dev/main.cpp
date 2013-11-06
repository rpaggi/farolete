using namespace std;

// Classes Includes
#include "Display.hpp"
#include "SceneManager.hpp"
//#include "SceneSplash1.hpp"
#include "GamePlay.hpp"

// Main Processrm 
int main(){
	Display display;
	SceneManager sceneManager;
	//Scene * firstScene = new SceneSplash1(&display);
	Scene * firstScene = new GamePlay(&display);

	sceneManager.setDisplay(&display);
	sceneManager.setCurrentScene(firstScene);
	sceneManager.run();

	return 0;
}