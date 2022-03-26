//pointersAndBubbles.c
//famous bubble sort
//implement the swap algorithm with pointers

#include <stdio.h>
#define MAX 9

//function prototypes

int values[] = {7, 3, 9, 4, 6, 1, 2, 8, 5}; //initialize required array 

void printValues(){                         //function to print values
	printf("\n[");
	int k;                              //initialize k
	for(k = 0; k < MAX; k++){           //initialize for loop to traverse through array
		printf("%d ", *(values+k)); //print values in array at sentry variable value
	}
	printf("]");
}
void swap(int* firstVal, int* secondVal){   //function to swap values of two variables
        int temp = *firstVal;               
        *firstVal = *secondVal;             //change values of variable by using temporary variable
        *secondVal = temp;
} 
void sort(){                                //function to sort an array
	int i, j;
    	for(i = 0; i < MAX; i++){
      		for(j = 0; j < MAX - 1; j++){
        		if (*(values+j) > *(values+j+1)){   //using bubble sort to sort the array
          			swap(&*(values+j), &*(values+j+1));
				printValues();
			}	
       		}
    	}   
}

int main(){                                 //main function
	printf("\nBefore: \n");
    	printValues();                      //print values before sorting
      	sort();                             //sort array by calling sort() function
        printf("\nAfter: \n");             
        printValues();                      //print values after  sorting
	return(0);
} // end main
