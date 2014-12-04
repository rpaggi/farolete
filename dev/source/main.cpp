#define _WIN32_WINNT 0x0500

using namespace std;

#include <windows.h>
#include <stdlib.h>
//Classes Includes
#include "Display.hpp"
#include "SceneManager.hpp"
#include "SaveGame.hpp"
#include "Stage1.hpp"

// Main Processrm 
int main(){
	//To hide prompt
	// HWND hWnd = GetConsoleWindow();
	// ShowWindow( hWnd, SW_HIDE );

	srand(time(NULL));

	Display display;

	SaveGame saveGame;
	saveGame.loadGame();

	SceneManager sceneManager;
	// Scene * firstScene = new SceneSplash1(&display);
	Scene * firstScene = new Stage1(&display, saveGame);
	// Scene * firstScene = new Stage2(&display);
// Scene * firstScene = new GameOver(&display);

	sceneManager.setDisplay(&display);
	sceneManager.setCurrentScene(firstScene);
	sceneManager.run();

	return 0;
}

