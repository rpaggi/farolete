#include  "Stage2.hpp"
#include <iostream>

void Stage2::init(){
   mapLoader = new tmx::MapLoader("maps/map2/");
   mapLoader->Load("map2.tmx");

   float screen_x = display->getSize().x;
   float screen_y = display->getSize().y;

   fase = 2;
}

Stage2::Stage2(Display * d){
   display = d;
   this->init();
}
   
Stage2::Stage2(Display * d, SaveGame sg){
   display = d;
   saveGame = sg;
   this->init();
}


void Stage2::logic(){
   GamePlay::logic();
}