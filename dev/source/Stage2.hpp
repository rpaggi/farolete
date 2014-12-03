#ifndef STAGE2_HPP
#define STAGE2_HPP

#include "GamePlay.hpp"

class Stage2 : public GamePlay { 
private:
   void init();
public:
   Stage2(Display * d);
   Stage2(Display * d, SaveGame sg);

   void logic();
};

#endif