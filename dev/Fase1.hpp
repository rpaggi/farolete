#ifndef FASE1_HPP
#define FASE1_HPP

#include "Display.hpp"
#include "SceneManager.hpp"
#include "AssetsManager.hpp"

#include <SFML/Graphics.hpp>

// Resource ID for sf::Texture
namespace Textures
{
    enum ID
    {
        Landscape,
        Airplane,
    };
}


class Fase1 : public Scene {
	Display * display;

public:
	Fase1(Display * d);

	void start();
	void draw();
	void render();
	void logic();
	void finish();
};

#endif