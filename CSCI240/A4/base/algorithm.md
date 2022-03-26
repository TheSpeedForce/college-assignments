#Horse Race Algorithm
##Pawas Aggarwal

**Goals**
Build a program that simulates a horse race using OOP.

**Input**
Takes an integer, stores it in *seed* to use for seeding random numbers.

**Output**
Print a text based race simulation and the winner at the end.

**Steps** 
 - **Program Algorithm**
1. Initialize *horses*  array with starting postions as 0 for all horses.
2. Initialize *while*  loop until one of the horses reach the end.
3. Initialize *for*  loop to flip coin for every horse at every pass of while loop.
4. Get the value of coin flip and move the horse at *sentry value* of for loop ahead if coin value is 1.
5. *Print*  the race line for the horse with dots and horse number at *every pass* of for loop.
6. Check if the position of Horse is at the end, *if true*, end while loop.
7. *Print*  winnner.

 - ***horse.cpp:***
	 - **Horse()**
	 Constructor function.
	1. Set *Position* to 0.
	 - **advance()**
	 Function to advance horse position.
	1.  Initialize *coin* and set value using *rand()*
	2.  Increase *position* if *coin* is 1.
	 - **getPosition()**
	 Function to get position of horse.
	 1. Return **position**. 

- ***race.cpp:***
	- **Race()**
	Constructor Function.
	1. set default *length* to 15.
	- **printLine(horseNum)**
	1. Initialize first *for* loop  with *i* at 0 and add 1 to  until *i* is larger than *position*.
	2. Print *.* at every pass in same line.
	3. Print *horseNum*.
	4. Initialize second for loop with j at  	*position + 1* and *increase* j  by 1 until j is larger than 15.
	5. Print *.* at every pass in same line.
	6. Print new line

	- **start()**
	Function to start race simulation.
	1. Initalize *check, winner*  and *seed*  variables.
	2. Assign 0 to *check*.
	3. Input value for *seed*.
	4. Begin *while*  loop using check as condition variable.
	5. Begin *for*  loop inside *while*  loop with i at 0 and *increase*  i by 1 until i is larger than 5.
	6. If *check* is not equal to 1, call *advance* to advance horse.
	7. Call *printLane()* and pass *i*  as arguments.
	8. Get *position* for horse.
	9. Check if *position* is greater than 15. If *true*, assign value of *i* to *winner*  and *change* value of *check* to 1 to end *while* loop.
	10. Print winner.

- ***main.cpp***
	Main function to run the program.

	1.  create *race* object *r*
	2.  call *start()* function to start race.
	3. End program




