#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Game settings using define
#define MAX_ATTEMPTS 100
#define LOWER_BOUND 1
#define UPPER_BOUND 250

int main() {
    int number, guess, attempts = 0;

    // Seed random number generator
    srand(time(0));
    number = (rand() % (UPPER_BOUND - LOWER_BOUND + 1)) + LOWER_BOUND;

    printf("Welcome to the Number Guessing Game!\n");
    printf("Guess a number between %d and %d\n", LOWER_BOUND, UPPER_BOUND);

    while (attempts < MAX_ATTEMPTS) {
        printf("Attempt %d of %d: ", attempts + 1, MAX_ATTEMPTS);
        scanf("%d", &guess);
        attempts++;

        if (guess == number) {
            printf("Congratulations! You guessed the correct number %d in %d attempts.\n", number, attempts);
            break;
        } 
        else if (guess < number)
         {
            printf("Too low!\n");
        }
         else
         {
            printf("Too high!\n");
        }
    }

    if (guess != number) {
        printf("Sorry, you've used all your attempts. The correct number was %d.\n", number);
    }

    return 0;
}