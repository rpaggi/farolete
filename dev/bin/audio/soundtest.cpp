#include <SFML/Graphics.hpp>
#include <SFML/Audio/SoundBuffer.hpp>
#include <SFML/Audio/Sound.hpp>
#include <dos.h>

int main(){
    sf::RenderWindow window;
    window.create(sf::VideoMode(1024, 600), "xingu");
	sf::SoundBuffer soundBuffer;
	sf::Sound sound;

	soundBuffer.loadFromFile("walk.wav");
	sound.setBuffer(soundBuffer);

    while(window.isOpen()){
    	sf::Event event;
    	while(window.pollEvent(event)){
    		if(event.type == sf::Event::KeyPressed){
    			if(event.key.code == sf::Keyboard::P){
    				sound.play();
    			}else if(event.key.code == sf::Keyboard::Escape){
    				window.close();
    			}
    		}
    	}

    	window.display();
    }

	// sf::Music music;
	// music.openFromFile("walk.wav");
	// music.play();
}
