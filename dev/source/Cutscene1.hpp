#ifndef CUTSCENE1
#define CUTSCENE1

#include "Display.hpp"
#include "SceneManager.hpp"
#include "Input.hpp"

#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/System/Clock.hpp>
#include <SFML/System/Time.hpp>

/*>MOMENTO1 (0.75)
	+ALPHA SEQA 0 > 255
>MOMENTO2 (5)
	+MOSTRA SEQA
>MOMENTO3 (0.75)
	+ALPHA SEQA 255 > 0
	+ALPHA SEQB 0 > 255
>MOMENTO4(5)
	+MOSTRA SEQB
>MOMENTO5(0.75)
	+ALPHA SEQB 255 > 0
	+ALPHA SEQC 0 > 255
>MOMENTO6(5)
	+MOSTRA SEQC
>MOMENTO7(0.75)
	+ALPHA SEQC 255 > 0
	+ALPHA SEQD 0 > 255
>MOMENTO8(5)
	+MOSTRA SEQD
>MOMENTO9(0.75)
	+ALPHA SEQD 255 > 0*/

class Cutscene1:public Scene{
private:
	Display *          display;
	sf::Clock          clock;
	float              elapsed;

	KeyboardInput keyboard;
	GameKey     * space;

	sf::Texture        texSeqA;
	sf::Sprite         sprSeqA;

	sf::Texture        texSeqB;
	sf::Sprite         sprSeqB;

	sf::Texture        texSeqC;
	sf::Sprite         sprSeqC;

	sf::Texture        texSeqD;
	sf::Sprite         sprSeqD;
	
	int                momento;

	Scene            * goScene;

	void trataSprite(int function, sf::Sprite * sprite, float time);
public:
	Cutscene1(Display * display);
	void start();
	void draw();
	void render();
	void logic();
	void finish();
};

#endif