#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    // random seed
    srand(time(NULL));

    int arraySize; // declare int arraySize

    // ask user for size of array
    printf("Enter the size of the array: ");
    scanf("%d", &arraySize); // read input

    // create an array, size based on input, and numbers are random between -1000 and 1000
    int myArray[arraySize];
    for (int i = 0; i < arraySize; i++) {
        myArray[i] = rand() % 2001 - 1000; // generate random numbers between -1000 and 1000
    }

    // print the unsorted array if the size is small enough
    if (arraySize <= 25) {
        printf("Unsorted Array:\n");
        for (int i = 0; i < arraySize; i++) {
            printf("%d ", myArray[i]);
        }
        printf("\n");
    } else {
        printf("Array size is too large to display unsorted.\n");
    }

    // start the timer
    clock_t startTime = clock();

    // bubble sorting algorithm
    for (int i = 0; i < arraySize - 1; i++) {
        for (int j = 0; j < arraySize - i - 1; j++) {
            if (myArray[j] > myArray[j + 1]) {
                // swap the elements if they are in the wrong order
                int temp = myArray[j];
                myArray[j] = myArray[j + 1];
                myArray[j + 1] = temp;
            }
        }
    }

    // stop the timer
    clock_t endTime = clock();

    // print the sorted array if the size is small enough
    if (arraySize <= 20) {
        printf("Sorted Array:\n");
        for (int i = 0; i < arraySize; i++) {
            printf("%d ", myArray[i]);
        }
        printf("\n");
    } else {
        printf("Array size is too large to display sorted.\n");
    }

    // calculate and display the elapsed time
    double elapsedTime = ((double)(endTime - startTime)) / CLOCKS_PER_SEC;
    printf("Elapsed Time: %.6f seconds\n", elapsedTime);

    return 0;
}