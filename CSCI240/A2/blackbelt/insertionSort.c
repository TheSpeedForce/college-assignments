#include <stdio.h>

#include <stdlib.h>

#define MAX 9                           //define constant MAX with 9 

int values[] = {7, 3, 9, 4, 6, 1, 2, 8, 5}; //initialize array

void printValues(){                     //function to print values
    printf("\n[");
    int k;                              //initialize k
    for(k = 0; k < MAX; k++){           //initialize for loop to traverse through array
            printf("%d ", *(values+k)); //print values in array at sentry variable value
                    }
    printf("]");
}

void sort() {                           //function to sort arrray 
    int i,j,temp;                       //initialize required variables
    for(i = 1; i < MAX; i++) {
        temp = *(values+i);
        j = i-1;
        while( j >= 0 && *(values+j) > temp) { //sort using insertion sort
            *(values+(j+1))=*(values+j);
            j--;
        }
        *(values+(j+1))=temp;
        printf("\n");
        printValues();                   //print array at every change
    }
}
int main() {                             //main function
    printf("\nBefore:"); 
    printValues();                       //print array before sort
    sort();                              //call sort function to sort array
    printf("\nAfter:");
    printValues();                       //print array after sort
    return 0;
}

