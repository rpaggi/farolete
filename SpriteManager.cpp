#include "SpriteManager.hpp"

SpriteManager::SpriteManager() {}

void SpriteManager::start(Display * d, std::string file, int countF, int refreshRate){
    refreshRate = refreshRate;
    counter = 0; 
	display = d;
	texture.loadFromFile("imgMenu/menu_bg.png");
	countFrames = countF;
	fSize.x = texture.getSize().x/countF;
	fSize.y = texture.getSize().y;
	sprite.setTexture(texture);
	sprite.setTextureRect(sf::IntRect(0, 0, fSize.x, fSize.y));
	sprite.setPosition(0,0);
}

void SpriteManager::draw(){
    display->draw(sprite);
}

void SpriteManager::change(){
    if (counter % refreshRate) {
        counter++;
        return;
    }
	sf::IntRect texRect = sprite.getTextureRect();

	if((texRect.left+fSize.x) < texture.getSize().x){
		sprite.setTextureRect(sf::IntRect((texRect.left+fSize.x), 0, fSize.x, fSize.y));
	}else{
		sprite.setTextureRect(sf::IntRect(0, 0, fSize.x, fSize.y));
	}
    counter = 1;
}

void SpriteManager::setPosition(float x, float y){
	sprite.setPosition(x,y);
}

sf::Sprite SpriteManager::getSprite(){
	return sprite;
}
