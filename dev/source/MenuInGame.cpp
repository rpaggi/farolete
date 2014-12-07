#include "MenuInGame.hpp"

MenuInGame::MenuInGame(Display * d){
	display = d;

	w_key = new GameKey(sf::Keyboard::W);
	s_key = new GameKey(sf::Keyboard::S);
	enter = new GameKey(sf::Keyboard::Return);

	texBg.loadFromFile("images/menuingame/background.png");
	texBtnRetornar.loadFromFile("images/menuingame/btnRetornar.png");
	texBtnMenuPrincipal.loadFromFile("images/menuingame/btnMenuPrincipal.png");

	sprBg.setTexture(texBg);
	sprBtnRetornar.setTexture(texBtnRetornar);
	sprBtnRetornar.setTextureRect(sf::IntRect(0, texBtnRetornar.getSize().y/2, texBtnRetornar.getSize().x, texBtnRetornar.getSize().y/2));

	sprBtnMenuPrincipal.setTexture(texBtnMenuPrincipal);
	sprBtnMenuPrincipal.setTextureRect(sf::IntRect(0, 0, texBtnMenuPrincipal.getSize().x, texBtnMenuPrincipal.getSize().y/2));

	verdana.loadFromFile("font/verdanab.ttf");

	txtXp.setFont(verdana);
	txtXp.setCharacterSize(20);
	txtXp.setColor(sf::Color::Black);

	txtHp.setFont(verdana);
	txtHp.setCharacterSize(20);
	txtHp.setColor(sf::Color::Black);

	txtBullets.setFont(verdana);
	txtBullets.setCharacterSize(20);
	txtBullets.setColor(sf::Color::Black);

	txtStamina.setFont(verdana);
	txtStamina.setCharacterSize(20);
	txtStamina.setColor(sf::Color::Black);

	selected = 1;
}

void MenuInGame::draw(){
	display->draw(sprBg);	
	display->draw(sprBtnRetornar);	
	display->draw(sprBtnMenuPrincipal);	
	display->draw(txtXp);
	display->draw(txtHp);
	display->draw(txtBullets);
	display->draw(txtStamina);
}

int MenuInGame::update(int xp, int hp, int bullets, int stamina){
	sf::View view = display->getView();
	sf::Vector2f sPosition = sf::Vector2f(view.getCenter().x - display->getSize().x/2, view.getCenter().y - display->getSize().y/2);

	std::ostringstream ss;

	if(xp<10){
		ss<<"0"<<xp;
	}else{
		ss<<xp;
	}
	txtXp.setString(ss.str());

	ss.str("");
	if(hp<10){
		ss<<"0"<<hp;
	}else{
		ss<<hp;
	}
	txtHp.setString(ss.str());

	ss.str("");
	if(bullets<10){
		ss<"0"<bullets;
	}else{
		ss<<bullets;
	}
	txtBullets.setString(ss.str());

	ss.str("");
	if(stamina<10){
		ss<<"0"<<stamina;
	}else{
		ss<<stamina;
	}
	txtStamina.setString(ss.str());

	if (keyboard.pressed(*w_key))
		selected = 1;
	else if (keyboard.pressed(*s_key))
		selected = 2;

	if (keyboard.pressed(*enter)){
		if(selected == 1){
			return 1;
		}else{
			return 2;
		}
	}

	if(selected == 1){
		sprBtnRetornar.setTextureRect(sf::IntRect(0, texBtnRetornar.getSize().y/2, texBtnRetornar.getSize().x, texBtnRetornar.getSize().y/2));
		sprBtnMenuPrincipal.setTextureRect(sf::IntRect(0, 0, texBtnMenuPrincipal.getSize().x, texBtnMenuPrincipal.getSize().y/2));
	}else{
		sprBtnRetornar.setTextureRect(sf::IntRect(0, 0, texBtnRetornar.getSize().x, texBtnRetornar.getSize().y/2));
		sprBtnMenuPrincipal.setTextureRect(sf::IntRect(0, texBtnMenuPrincipal.getSize().y/2, texBtnMenuPrincipal.getSize().x, texBtnMenuPrincipal.getSize().y/2));

	}

	sprBg.setPosition(sPosition.x + 292, sPosition.y + 112);
	sprBtnRetornar.setPosition(sPosition.x + 669, sPosition.y + 450);
	sprBtnMenuPrincipal.setPosition(sPosition.x + 601, sPosition.y + 507);
	txtXp.setPosition(sPosition.x + 705, sPosition.y + 225);
	txtHp.setPosition(sPosition.x + 910, sPosition.y + 225);
	txtBullets.setPosition(sPosition.x + 705, sPosition.y + 331);
	txtStamina.setPosition(sPosition.x + 910, sPosition.y + 331);

	return 0;
}