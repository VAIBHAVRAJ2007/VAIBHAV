#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define choices
#define ROCK 1
#define PAPER 2
#define SCISSORS 3

void printChoice(int choice) {
    switch (choice) {
        case ROCK: printf("Rock"); break;
        case PAPER: printf("Paper"); break;
        case SCISSORS: printf("Scissors"); break;
        default: printf("Invalid"); break;
    }
}

int main() {
    int playerChoice, computerChoice;

    // Seed random number generator
    srand(time(0));

    printf("Rock, Paper, Scissors Game!\n");
    printf("1 = Rock\n2 = Paper\n3 = Scissors\n");
    printf("Enter your choice: ");
    scanf("%d", &playerChoice);

    // Generate computer's choice
    computerChoice = (rand() % 3) + 1;

    printf("You chose: ");
    printChoice(playerChoice);
    printf("\nComputer chose: ");
    printChoice(computerChoice);
    printf("\n");

    // Decide the result
    if (playerChoice == computerChoice) {
        printf("It's a draw!\n");
    } else if ((playerChoice == ROCK && computerChoice == SCISSORS) ||
               (playerChoice == PAPER && computerChoice == ROCK) ||
               (playerChoice == SCISSORS && computerChoice == PAPER)) {
        printf("You win!\n");
    } else {
        printf("You lose!\n");
    }

    return 0;
}