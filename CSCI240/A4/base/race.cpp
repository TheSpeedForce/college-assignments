#include <iostream>
#include <stdlib.h>
#include "horse.h"
#include "race.h"

Race::Race(){ 
 Race::length = 15;                                   //set default length
}                                                     //end constructor

Race::Race(int length){                               //function to set length of track
  Race::length = length;                      
}

void Race::printLane(int horseNum){                   //function to print race lines.
  int position = Race::h[horseNum].getPosition();     //get position of horse
  for(int i = 0; i < position; i++){                  //first loop to print dots before horse
    std::cout << ".";
  }
  std::cout << horseNum;                              //print horse
  for(int j = position + 1 ; j < Race::length ; j++){ //print dots after horse
    std::cout << ".";
  }
  std::cout << "\n";
}

void Race::start(){                                   //function to start race
  int winner, check, seed;                            //initialize required variables
  check = 0;
  std::cout << "Enter number for seeding: ";          //Ask user for seed
  std::cin >> seed;
  srand(seed);                                      
  while (check == 0) {                                //loop to run until horse reaches end
    std::cout << "\n";
    for(int i = 0; i < 5; i++){                       //loop to advance horses
      if (check != 1){
      	Race::h[i].advance();                         //call advance function to advance horse                      
      }  
      Race::printLane(i);                             //call printLane to print race lines
      int position = Race::h[i].getPosition();        //get horse position
      if (position == 15){                            //check if horse is at the end
        winner = i;
        check = 1;
      }                          
    }
    std::cout << "\n";
  }
  std::cout<<"Horse " << winner << " wins!\n";        //Print winner horse
}
