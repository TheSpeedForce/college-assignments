#include <iostream>
#include <stdlib.h>
#include <time.h>
#define SIZE 5                                              //define size                   

int coinFlip(){                                             //function to flip a coinFlip
  int coin = 0 + rand()%2;                                  //initialize coin with value using rand() function
  return coin;                                              //return value of coin
}                                                           //end coinFlip()

void printRace(int horse, int position){                    //Function print race lines
  std::cout << "\n";
  for(int i = 0; i < position; i++){                        //first for loop to print dots before the horse position
    std::cout << ".";
  }
  std::cout << horse;                                       //print horse number
  for(int j = position + 1 ; j < 15; j++){                  //print dots after horse number
    std::cout << ".";
  }
  std::cout << "\n";
}                                                           //end printRace()

int startRace(int racers[SIZE]){                            //Function to start race simulation
  int check, winner;                                        //initialize required variables
  check = 0;                                                //set value for check
  while(check == 0){                                        //initialize while loop with check as sentry variable
    std::cout << "\n\n";
    for(int i = 0; i < SIZE; i++){                          //for loop to flip coin and move for every horse
      int move = coinFlip();
      if(move == 1){                                        //condtion to check if horse should move
        racers[i]++;
      }
      printRace(i, racers[i]);                              //call printRace() function to print race line
      if(racers[i] == 15){                                  //condition to check if the horse is at end
        winner = i;                                         //set winner if true
        check = 1;
	for(int j = i + 1; j < 5; j++){                     //Print remaining race lines
	  printRace(j, racers[j]);                          
        }
      break;                                                //break loop
      }
    }  
  }
  return winner;                                            //return value of winner
}                                                           //end startRace()

int main() {                                                //main function
  int horses[SIZE] = {0,0,0,0,0};                           //initialize horses array
  int choice;                                               //initialize choice variable

  std::cout << "\nEnter 1 to select seeding number of choice. \nEnter 2 to automate program:"<< std::endl;

  std::cin >> choice;                                       //input choice
  if(choice == 1){
    int seed;
    std::cout << "Enter number for seeding: ";
    std::cin >> seed;                                         //get input from user for seeding
    srand(seed);  
    int winner = startRace(horses);                           //call startRace() to start race, pass horses as argument and assign winner.
    std::cout << "\n\n";
    std::cout << "Horse " << winner << " wins!"<< std::endl;  //print winner
  } 
  else if (choice == 2){
    srand(time(NULL));                                        //seed using time
    int winner = startRace(horses);                           //call startRace() to start race, pass horses as argument and assign winner.
    std::cout << "\n\n";
    std::cout << "Horse " << winner << " wins!"<< std::endl;  //print winner
  }
  else{
    std::cout << "Invalid input, exiting program." << std::endl;
  }                  
}                                                              //end main()
                                                                            
