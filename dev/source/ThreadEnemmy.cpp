#include "ThreadEnemmy.hpp"

ThreadEnemmy::ThreadEnemmy(std::vector<CharEnemmy *> enemmies, CharMain * charmain, Display * dis){
   sf::Context context;
   this->display = dis;
   this->enemmies = enemmies;
   this->charmain = charmain;
   this->view = display->getView();
}

void ThreadEnemmy::draw(){
   for(unsigned i=0; i<enemmies.size();i++){
      enemmies[i]->draw();
   }
}

void ThreadEnemmy::update(){
   for(unsigned i=0; i<enemmies.size();i++){
      enemmies[i]->update();
      if((enemmies[i]->testVision() && !charmain->getHidden())
      ||  enemmies[i]->getFollow()  && !charmain->getHidden()){
         enemmies[i]->follow(view.getCenter());
      }else{
         enemmies[i]->follow(sf::Vector2f(-1,-1));
      }
   }
}