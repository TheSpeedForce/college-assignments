//horse.h
#ifndef HORSE_H_EXISTS
#define HORSE_H_EXISTS

#include <iostream>
#include <stdlib.h>

class Horse{                               //begin class definition.
  private:
    int position;                          //class properties
  public:
    Horse();
    void advance();                        //class methods
    int getPosition();
};                                         //end class definition
#endif
