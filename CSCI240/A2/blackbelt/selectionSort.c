#include <stdio.h>

#include <stdlib.h>

#define MAX 9                               //Define constant max with value 9

int values[] = {7, 3, 9, 4, 6, 1, 2, 8, 5}; //initialize arrray

void printValues(){                         //function to print values
    printf("\n[");
    int k;                                  //initialize k
    for(k = 0; k < MAX; k++){               //initialize for loop to traverse through array
            printf("%d ", *(values+k));     //print values in array at sentry variable value
                    }
    printf("]");
}

void swap(int* firstVal, int* secondVal){   //function to swap values of two variables
        int temp = *firstVal;
        *firstVal = *secondVal;             //change values of variable by using temporary variable
        *secondVal = temp;
}

void sort() {                               //function to sort arrray 
    int i, j, min;                          //initialize required variables
    for(i = 0; i < MAX; i++) {              //initialize for loop with i
        min = i;                               
        for(j = i+1; j < MAX; j++){
          if (*(values + j) < *(values + min)){        //sort using selection sort
            min = j;
          }
        }
        swap(&*(values + i), &*(values + min));
        printValues();                       //print array after every change
    }
}
int main() {                                 //main functions
    printf("\nBefore:"); 
    printValues();                           //print array before sorting
    sort();                                  //call sort function to sort
    printf("\nAfter:");
    printValues();                           //print array after sorting
    return 0;                                //end functions
}
