#include "GameOver.hpp"
#include "Stage1.hpp"
#include "Stage2.hpp"
#include "MainMenu.hpp"
#include <iostream>

GameOver::GameOver(Display * dis){
	display = dis;
}

void GameOver::start(){
	a_key = new GameKey(sf::Keyboard::A);
	d_key = new GameKey(sf::Keyboard::D);
	enter = new GameKey(sf::Keyboard::Return);
	end = new GameKey(sf::Keyboard::End);

	moment = 1;
	selected = 1;
	alpha = 255;

	texBg.loadFromFile("images/gameover/background.png");
	sprBg.setTexture(texBg);
	sprBg.setPosition(0,0);

	texBtnContinue.loadFromFile("images/gameover/btnContinue.png");
	sprBtnContinue.setTexture(texBtnContinue);
	sprBtnContinue.setPosition(250,650);
	sprBtnContinue.setTextureRect(sf::IntRect(0, 55, 344, 55));

	texBtnExit.loadFromFile("images/gameover/btnExit.png");
	sprBtnExit.setTexture(texBtnExit);
	sprBtnExit.setPosition(800,650);
	sprBtnExit.setTextureRect(sf::IntRect(0, 0, 137, 55));

	blackScreen.setSize(display->getSize2f());
	blackScreen.setOutlineThickness(0);
	blackScreen.setPosition(0,0);
	blackScreen.setFillColor(sf::Color(0,0,0,alpha));

}
void GameOver::draw(){
	display->clear(sf::Color(255,0,0,255));
	display->draw(sprBg);
	display->draw(sprBtnContinue);
	display->draw(sprBtnExit);
	display->draw(blackScreen);
}
void GameOver::render(){
	display->display();
}

void GameOver::logic(){
	elapsed = clock.getElapsedTime().asSeconds();

	switch(moment){
		case 1:
			if(elapsed > 0.75){
				moment = 2;
				alpha = 0;
				clock.restart();
			}else{
				alpha = 255-(340 * elapsed);
			}
		break;

		case 2:
    		if (keyboard.triggered(*a_key)) {
				sprBtnContinue.setTextureRect(sf::IntRect(0, 55, 344, 55));
				sprBtnExit.setTextureRect(sf::IntRect(0, 0, 137, 55));
    			selected = 1;
    		}else if (keyboard.triggered(*d_key)) {
				sprBtnContinue.setTextureRect(sf::IntRect(0, 0, 344, 55));
				sprBtnExit.setTextureRect(sf::IntRect(0, 55, 137, 55));
    			selected = 2;
    		}else if (keyboard.triggered(*enter)) {
    			if(selected == 1){
    				SaveGame savegame;
    				savegame.loadGame();

    				if(savegame.stage == 1){
    				    goScene = new Stage1(display, savegame);
    				}else{
    				    goScene = new Stage2(display, savegame);
    				}
    			}else{
    				goScene = new MainMenu(display);
    			}
    			moment = 3;
    			clock.restart();
    		}else if(keyboard.triggered(*end)){
    			sceneManager->exit();
    		}
		break;

		case 3:
			if(elapsed > 0.75){
                sceneManager->setCurrentScene(goScene);
			}else{
				alpha = 340 * elapsed;
			}
		break;
	}
	blackScreen.setFillColor(sf::Color(0,0,0,alpha));

}

void GameOver::finish(){}