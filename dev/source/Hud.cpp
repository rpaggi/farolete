#include "Hud.hpp"
#include <iostream>

Hud::Hud(Display * d){
   display = d;

   //Load and set the texture of background into sprite
   bgTex.loadFromFile("images/hud/bg.png");
   bgSpr.setTexture(bgTex);

   hpTex.loadFromFile("images/hud/hp.png");
   hpSpr.setTexture(hpTex);
   hpSpr.setTextureRect(sf::IntRect(0, 0, 157, 25));

   stTex.loadFromFile("images/hud/stamina.png");
   stSpr.setTexture(stTex);
   stSpr.setTextureRect(sf::IntRect(0, 0, 157, 25));

   gTex.loadFromFile("images/hud/guns.png");
   gSpr.setTexture(gTex);
   gSpr.setTextureRect(sf::IntRect(0, 0, 82, 22));

   bTex.loadFromFile("images/hud/bullets.png");
   bFont.loadFromFile("images/hud/verdana.ttf");
   bSpr.setTexture(bTex);
   bSpr.setTextureRect(sf::IntRect(0, 0, 36, 21));
   bText.setFont(bFont);
   bText.setString("20");
   bText.setCharacterSize(10);
   bText.setColor(sf::Color::Red);
   bDraw = false;
}

void Hud::draw(){
   sf::View view = display->getView();
   sf::Vector2f bgPos;

   //Go to the end of the screen and subtract the background size with a margin of 10 pixels.
   // bgPos.x = (view.getCenter().x + (display->getSize().x/2)) - bgTex.getSize().x-10;
   bgPos.x = (view.getCenter().x - (display->getSize().x/2)) + 10;
   bgPos.y = (view.getCenter().y + (display->getSize().y/2)) - bgTex.getSize().y-10;
   // bgPos.y = (view.getCenter().y - (display->getSize().y/2)) + 10;

   //Set the position of background
   bgSpr.setPosition(bgPos);

   //Set the position of hp bar
   hpSpr.setPosition(bgPos.x+129, bgPos.y+30);

   //Set the position of stamina bar
   stSpr.setPosition(bgPos.x+129, bgPos.y+61);

   //Set the position of guns icons
   gSpr.setPosition(bgPos.x+171.1, bgPos.y+87.7);

   //Set the position of guns icons
   bSpr.setPosition(bgPos.x+128.5, bgPos.y+88);

   //Draw the sprites
   display->draw(bgSpr);
   display->draw(hpSpr);
   display->draw(stSpr);
   display->draw(gSpr);
   display->draw(bSpr);

   if(bDraw){
      //Set the position of text 
      bText.setPosition(bgPos.x+141, bgPos.y+98);
      display->draw(bText);
   }
}

void Hud::update(float hp, float st, int g, int b){
   //Update the hp bar
   if(hp>=90 && hp <=100){
      hpSpr.setTextureRect(sf::IntRect(0, 0, 157, 25));
   }else if(hp>=80 && hp<90){
      hpSpr.setTextureRect(sf::IntRect(0, (25*2), 157, 26));
   }else if(hp>=70 && hp<80){
      hpSpr.setTextureRect(sf::IntRect(0, (25*3), 157, 25));
   }else if(hp>=60 && hp<70){
      hpSpr.setTextureRect(sf::IntRect(0, (25*4), 157, 25));
   }else if(hp>=50 && hp<60){
      hpSpr.setTextureRect(sf::IntRect(0, (25*5), 157, 25));
   }else if(hp>=40 && hp<50){
      hpSpr.setTextureRect(sf::IntRect(0, (25*6), 157, 25));
   }else if(hp>=30 && hp<40){
      hpSpr.setTextureRect(sf::IntRect(0, (25*7), 157, 25));
   }else if(hp>=20 && hp<30){
      hpSpr.setTextureRect(sf::IntRect(0, (25*8), 157, 25));
   }else if(hp>=10 && hp<20){
      hpSpr.setTextureRect(sf::IntRect(0, (25*9), 157, 25));
   }else if(hp>0 && hp<10){
      hpSpr.setTextureRect(sf::IntRect(0, (25*10), 157, 25));
   }else if(hp<0){
      hpSpr.setTextureRect(sf::IntRect(0, (25*11), 157, 25));
   }
   
   //Update the stamina bar
   if(st>=90 && st <=100){
      stSpr.setTextureRect(sf::IntRect(0, 0, 157, 25));
   }else if(st>=80 && st<90){
      stSpr.setTextureRect(sf::IntRect(0, (25*2), 157, 26));
   }else if(st>=70 && st<80){
      stSpr.setTextureRect(sf::IntRect(0, (25*3), 157, 25));
   }else if(st>=60 && st<70){
      stSpr.setTextureRect(sf::IntRect(0, (25*4), 157, 25));
   }else if(st>=50 && st<60){
      stSpr.setTextureRect(sf::IntRect(0, (25*5), 157, 25));
   }else if(st>=40 && st<50){
      stSpr.setTextureRect(sf::IntRect(0, (25*6), 157, 25));
   }else if(st>=30 && st<40){
      stSpr.setTextureRect(sf::IntRect(0, (25*7), 157, 25));
   }else if(st>=20 && st<30){
      stSpr.setTextureRect(sf::IntRect(0, (25*8), 157, 25));
   }else if(st>=10 && st<20){
      stSpr.setTextureRect(sf::IntRect(0, (25*9), 157, 25));
   }else if(st>0 && st<10){
      stSpr.setTextureRect(sf::IntRect(0, (25*10), 157, 25));
   }else if(st<0){
      stSpr.setTextureRect(sf::IntRect(0, (25*11), 157, 25));
   }

   if(g == 1){
      gSpr.setTextureRect(sf::IntRect(0, 22*2, 82, 22));
   }else if(g == 2 || g == 3){
      gSpr.setTextureRect(sf::IntRect(0, 22*1, 82, 22));
   }else if(g == 4 || g == 5){
      gSpr.setTextureRect(sf::IntRect(0, 22*3, 82, 22));
   }else{
      gSpr.setTextureRect(sf::IntRect(0, 0, 82, 22));
   }

   if(g<=1){
      bSpr.setTextureRect(sf::IntRect(0, 0, 36, 21));
   }else{
      if(b<=0){
         bSpr.setTextureRect(sf::IntRect(0, 21, 36, 21));
      }else{
         bDraw = true;
         bSpr.setTextureRect(sf::IntRect(0, 42, 36, 21));
      }
   }

}