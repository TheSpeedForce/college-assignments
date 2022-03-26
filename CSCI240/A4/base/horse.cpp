#include <iostream>
#include <stdlib.h>
#include "horse.h"

Horse::Horse(){
  Horse::position = 0;                //set beginning position
}                                     //end constructor

void Horse::advance(){                //function to advance horse
  int coin  = 0 + rand()%2;           //flip coin using random function
  if (coin == 1){
    Horse::position++;                //move horse if coin is 1
  }
}

int Horse::getPosition(){             //function to get horse position
  return Horse::position;
}
