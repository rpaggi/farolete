#ifndef STAGE1_HPP
#define STAGE1_HPP

#include "GamePlay.hpp"

class Stage1 : public GamePlay { 
public:
   Stage1(Display * d);

   void logic();
};

#endif