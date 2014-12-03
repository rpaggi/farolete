#include  "Stage1.hpp"
#include <iostream>

void Stage1::init(){
   mapLoader = new tmx::MapLoader("maps/map1/");
   mapLoader->Load("map1.tmx");

   float screen_x = display->getSize().x;
   float screen_y = display->getSize().y;

   fase = 1;
}

Stage1::Stage1(Display * d){
   display = d;
   this->init();
}

Stage1::Stage1(Display * d, SaveGame sg){
   display = d;
   saveGame = sg;
   this->init();
}

void Stage1::logic(){
   GamePlay::logic();
}