#include <stdio.h>
#include <stdlib.h> //include functions for the random number generator

//main method
int main() {
    
    srand(time(NULL)); //function to reset the RNG seed

    int goal = rand() % 50 + 1; //decalre "goal",this is the Random number, between 1-50
    int guess; //declare int for user's guess
    int numberOfGuesses = 1; //declare int for user's number of guesses

    //while loop runs while the user guessed less than 10 times
    while (numberOfGuesses <= 10) {
        printf("Enter your Guess (between 1 and 50):"); //prompts user to guess
        scanf("%d", & guess); //reads user's guess

        //if the guess is less than the Random number
        if (guess < goal) {
            printf("Too low ..."); //print its too low
            
        //if else the guess is higher than the Random number    
        } else if (guess > goal) {
            printf("Too high ..."); //print the guess is too high
        
        //else print out the user guess the Random number correctly
        } else {
            printf("Correct, the number was %d", goal); //print out winner message
            break; //break the while loop
        }

        numberOfGuesses++; //increment the number of guesses by 1 each loop
    }
    
    //if the user guessed more than 10 times print out loser message
    if (numberOfGuesses > 10) {
        printf("Sorry, the number was %d", goal);
    }
    
    return 0;
}