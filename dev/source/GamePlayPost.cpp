#include "GamePlayPost.hpp"
#include "Cutscene2.hpp"
#include "Cutscene3.hpp"
#include "GameOver.hpp"
#include "MainMenu.hpp"

GamePlayPost::GamePlayPost(Display * d, int t){
	tela = t;
	display = d;
}

void GamePlayPost::start(){
	if(tela == 1){
		goScene = new MainMenu(display);
	}
	if(tela == 2){
		goScene = new GameOver(display);
	}
	if(tela == 3){
		goScene = new Cutscene2(display);
	}
	if(tela == 4){
		goScene = new Cutscene3(display);
	}
}

void GamePlayPost::logic(){
	float elapsed = clock.getElapsedTime().asSeconds();

	if(elapsed > 0.5)
		sceneManager->setCurrentScene(goScene);
}