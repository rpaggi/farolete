#ifndef STAGE1_HPP
#define STAGE1_HPP

#include "GamePlay.hpp"

class Stage1 : public GamePlay { 
private:
   void init();
public:
   Stage1(Display * d);
   Stage1(Display * d, SaveGame sg);

   void logic();
};

#endif