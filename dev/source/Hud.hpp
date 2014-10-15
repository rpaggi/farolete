#ifndef HUD_HPP
#define HUD_HPP

#include "Display.hpp"

#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/Text.hpp>

class Hud{
private:
   Display *         display;

   sf::Texture       bgTex;
   sf::Sprite        bgSpr;

   sf::Texture       hpTex;
   sf::Sprite        hpSpr;

   sf::Texture       stTex;
   sf::Sprite        stSpr;

   sf::Texture       gTex;
   sf::Sprite        gSpr;

   sf::Texture       bTex;
   sf::Sprite        bSpr;
   sf::Font          bFont;
   sf::Text          bText;
   bool              bDraw;

public:
   Hud(Display * d);

   void draw();

   void update(float hp, float st, int g, int b);
};

#endif