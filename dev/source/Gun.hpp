#ifndef GUN_HPP
#define GUN_HPP

#include <string>

class Gun { 
protected:
   int         id;
   char        name[50];
   int         range;  // 1- Close | 2- Average | 3- Far
   int         cadence; 
   int         damage; // 1- Low | 2- Medium | 3- High
   int         weight; // l- Null | 2- Light | h- Heavy
public:
   Gun();

   int         getId();
   std::string getName();
   int         getRange();
   int         getCadence();
   int         getDamage();
   int         getWeight();
};

#endif