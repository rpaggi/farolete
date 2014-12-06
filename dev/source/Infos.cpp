#include "Infos.hpp"
#include "MainMenu.hpp"

Infos::Infos(Display * display){
	this->display = display;
}

void Infos::start(){
    display->setShowMousePointer(false);

    sf::View view(sf::FloatRect(0,0,display->getSize().x, display->getSize().y));
    display->setView(view);

    esc = new GameKey(sf::Keyboard::Escape);

	texBg.loadFromFile("images/infos/background.png");
	sprBg.setTexture(texBg);
	sprBg.setColor(sf::Color(255,255,255,0));

	momento = 0;

	clock.restart();
}

void Infos::draw(){
	display->clear(sf::Color::Black);
	display->draw(sprBg);
}

void Infos::render(){
	display->display();
}

void Infos::logic(){
	elapsed = clock.getElapsedTime().asSeconds();
	switch(momento){
		case 0:
			if(keyboard.triggered(*esc)){
				momento = 1;
				clock.restart();
			}
			trataSprite(2, &sprBg, 0);
		break;

		case 1:
			if(elapsed > 0.35){
				sprBg.setColor(sf::Color(255,255,255,0));
				goScene = new MainMenu(display);
				sceneManager->setCurrentScene(goScene);
			}else{
				trataSprite(3, &sprBg, 0.35);
			}
		break;
	}
}

void Infos::finish(){
	delete this;
}

void Infos::trataSprite(int function, sf::Sprite * sprite, float time){
	int value = 255/time;
	float alpha = 255;

	switch(function){
		// Fade-in
		case 1:
			alpha = value * elapsed;
			// alpha = 255-(value * elapsed);
		break;

		// Show only
		case 2:
			alpha = 255;
		break;

		// Fade-out
		case 3:
			alpha = 255-(value * elapsed);
			// alpha = value * elapsed;
		break;
	}

	sprite->setColor(sf::Color(255,255,255,alpha));
}
