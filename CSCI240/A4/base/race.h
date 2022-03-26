#ifndef RACE_H_EXISTS
#define RACE_H_EXISTS

#include <iostream>
#include <stdlib.h>
#include "horse.h"

class Race {                         //begin class definition
  private:
    Horse h[5];                      //call Horse class to create array of Horse objects
    int length;                       
  public:
    Race();
    Race(int length);
    void printLane(int horseNum);    //class methods
    void start();
};                                   //end class definition
#endif
