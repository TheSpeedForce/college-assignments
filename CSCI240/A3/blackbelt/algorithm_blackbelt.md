#Horse Race Algorithm
##Pawas Aggarwal

**Goals**
Build a program that simulates a horse race with *automation* option.

**Input**
Takes an *integer*, stores it in *choice* to select option. Takes another *integer*, stores it in *seed* to use for seeding random numbers. 

**Output**
Print a text based race simulation and the winner at the end.

**Steps** 
A) To simulate horse race:
1. Initialize *horses*  array with starting postions as 0 for all horses.
2. Initialize *while*  loop until one of the horses reach the end.
3. Initialize *for*  loop to flip coin for every horse at every pass of while loop.
4. Get the value of coin flip and move the horse at *sentry value* of for loop ahead if coin value is 1.
5. *Print*  the race line for the horse with dots and horse number at *every pass* of for loop.
6. Check if the position of Horse is at the end, *if true*,, end while loop.
7. *Print*  winnner.

B) To automate:
1. Seed using *time*.
2. Simulate race using above algorithm.

- **coinFlip()**
Function to flip a coin. Returns an integer.

1. Initialiaze *coin* and assign random value between 0 or 1 using *rand()* function.
2. return coin

- **printRace(horse, position)**
Function to print race line. Takes two parameters, horse number and that horse position. Returns an integer.

1. Initialize first *for* loop  with *i* at 0 and add 1 to  until *i* is larger than *position*.
2. Print *.* at every pass in same line.
3. Print *horse*.
4. Initialize second for loop with j at  *position + 1* and *increase* j  by 1 until j is larger than 15.
5. Print *.* at every pass in same line.
6. Print new line

- **startRace()**
Function to start race simulation. Takes an *array **racers[]*** as parameter. Returns integer.

1. Initalize *check, winner* .
2. Assign 0 to *check*.
3. Input value for *seed*.
4. Begin *while*  loop using check as condition variable.
5. Begin *for*  loop inside *while*  loop with i at 0 and *increase*  i by 1 until i is larger than defined SIZE.
6. Inside *for*  loop,  initialize *move* and assign value returned by calling *coinFlip()*.
7. If *move* is equal to 1, increase value in *racers[]* at *i* by 1.
8. Call *printRace()* and pass *i* and *racers[i]* as arguments.
9. Check if *racers[i]* is greater than 15. If *true*, assign value of *i* to *winner*  and *change* value of *check* to 1 to end *while* loop.
10. Print remaining race lines. Break *for* loop.
10. *Return* winner.

- **main()**
Main function to run the program.

1. Initialize array *horses* with defined *SIZE* .
2. Initialize *choice*.
3. Input *choice* from user.
4. Check input value. 
A) If *choice* is 1, 
	1. Initialize *seed*, input *seed* value, seed random number using *srand(seed)* . 
	2. Then initialize*winner* and call *startRace()* to start simulation and get value for *winner*. 
	3. *Print* value of *winner*
	4. End program.

   B) If *choice* is 2,
   1. Seed using *time*.
   2. Then initialize*winner* and call *startRace()* to start simulation and get value for *winner*. 
   3. *Print* value of *winner*
   4. End program.
   
   C) Else,
   1. Print *Invalid Input*
   2. End Program.
