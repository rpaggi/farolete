#ifndef STAGE2_HPP
#define STAGE2_HPP

#include "GamePlay.hpp"

class Stage2 : public GamePlay { 
public:
   Stage2(Display * d);

   void logic();
};

#endif