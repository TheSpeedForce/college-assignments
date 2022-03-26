#include <iostream>
#include <stdlib.h>

int horses[5] = {0, 0, 0, 0, 0};                            //initialize required horses array

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

int startRace(){
  int check, winner, seed;                                  //initialize required variables
  check = 0;                                                //set value for check
  std::cout << "Please enter a random seed: ";
  std::cin >> seed;                                         //get input from user for seeding
  srand(seed);                                              //seed random number using input value
  while(check == 0){                                        //initialize while loop with check as sentry variable
    std::cout << "\n\n";
    for(int i = 0; i < 5; i++){                             //for loop to flip coin and move for every horse
      int move = coinFlip();
      if(move == 1){                                        //condtion to check if horse should move
        horses[i]++;
      }
      printRace(i, horses[i]);                              //call printRace() function to print race line
      if(horses[i] == 15){                                  //condition to check if the horse is at end
        winner = i;                                         //set winner if true
        check = 1;
	for(int j = i+1; j < 5; j++){                       //for loop to print remaining race lines.
	  printRace(j, horses[j]);
						            //end loop
        }
 	break;	                                            //break loop to stop horses moving further
      }
    }
  }
  return winner;
}
                                                            //end startRace()

int main() {                                                //main function
  int winner = startRace();                                 //call startRace() to start race and assign winner.
  std::cout << "\n\n";
  std::cout << "Horse " << winner << " wins!"<< std::endl;  //print winner
}                                                           //end main()
