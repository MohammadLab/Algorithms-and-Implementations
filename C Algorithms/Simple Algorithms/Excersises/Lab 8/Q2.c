#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    srand(time(NULL)); // random seed every run

    int arr[30]; // create array with 30 values
    int num;     // declare int value for the number to check the frequency of

    // Loop until the user enters a valid number (0 <= x <= 20)
    while (1)
    {
        printf("Enter an integer number in the range of 0 to 20: ");
        scanf("%d", &num);

        if (num >= 0 && num <= 20)
        {
            break; // exit the loop if the input is valid
        }
        else
        {
            printf("Invalid input. Please enter a number between 0 and 20.\n");
        }
    }

    int frequency = 0; // declare int variable for the frequency

    // populate array with 30 random numbers (Between 0-20)
    for (int i = 0; i < 30; i++)
    {
        arr[i] = rand() % 21;
    }

    // check every num in the array, if the int is == to num, increase "frequency" by 1
    for (int i = 0; i < 30; i++)
    {
        if (arr[i] == num)
        {
            frequency++;
        }
    }

    printf("Array:\n"); // print the array
    for (int i = 0; i < 30; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n"); // go to a new line

    // display the frequency of the given number
    printf("Frequency of %d in the array: %d\n", num, frequency);

    return 0;
}
