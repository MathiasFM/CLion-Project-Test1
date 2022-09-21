#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int randomNum(int lowerLimit, int upperLimit){
    srand(time(NULL));
    int random =  lowerLimit + rand() % (upperLimit - lowerLimit);
    return random;
}

int computerPlay(){
    int computerValue;

    computerValue = randomNum(1, 100);

    if (computerValue <= 33) {
        return 1;
    } else if (computerValue <= 66) {
        return 2;
    } else if (computerValue <= 99) {
        return 3;
    } else {
        return 0;
    }
}

int userPlay(){
    char userInput[200];
    printf("\n\nChoose Rock, Paper or Scissor: ");
    scanf("\n%s", userInput);

    for (int i = 0; userInput[i]; i++) {
        userInput[i] = tolower((unsigned char)userInput[i]);
    }

    if (!strcmp(userInput, "exit")) {
        return 0;
    } else if(strcmp(userInput, "rock") && strcmp(userInput, "paper") && strcmp(userInput, "scissor")) {
        printf("Wrong input, try again!");
        return userPlay();
    }

    if (!strcmp(userInput, "rock")) {
        return 1;
    } else if (!strcmp(userInput, "paper")) {
        return 2;
    } else if (!strcmp(userInput, "scissor")) {
        return 3;
    } else {
        return 0;
    }
}

int gameOutcome(){
    int computerOutput;
    int userOutput;

    userOutput = userPlay();
    computerOutput = computerPlay();


    if (computerOutput == userOutput) {
        return 1; //Tie
    } else if (computerOutput == 1 && userOutput == 3) {
        return 2; //C chose R beats S
    } else if (computerOutput == 2 && userOutput == 1) {
        return 2; //C chose P beats R
    } else if (computerOutput == 3 && userOutput == 2) {
        return 2; //C chose S beats P
    } else if (computerOutput == 1 && userOutput == 2) {
        return 3; //C chose R lost to P
    } else if (computerOutput == 2 && userOutput == 3) {
        return 3; //C chose P lost to S
    } else if (computerOutput == 3 && userOutput == 1) {
        return 3; //C chose S lost to R
    } else {
        return 0;
    }

}

char* gamePlay() {
    int playerScore = 0, computerScore = 0, gameResult;

    for (int i = 1; i < 50; i++) {
        gameResult = gameOutcome();
        if (playerScore == 4 || computerScore == 4) {
            if (playerScore == 4){
                printf("Round: %d", i);
                printf("\nFinal score is: (P) %d - (C) %d", playerScore + 1, computerScore);
                return "\nGame over! Player wins!";
            } else {
                printf("Round: %d", i);
                printf("\nFinal score is: (P) %d - (C) %d", playerScore, computerScore + 1);
                return "\nGame over! Computer wins!";
            }
        } else if (gameResult == 1) {
            printf("Round: %d", i);
            printf("\nIt's a tie! Score: (P) %d - (C) %d", playerScore, computerScore);
        } else if (gameResult == 2) {
            printf("Round: %d", i);
            ++computerScore;
            printf("\nComputer wins! Score: (P) %d - (C) %d", playerScore, computerScore);
        } else if (gameResult == 3) {
            printf("Round: %d", i);
            ++playerScore;
            printf("\nPlayer wins! Score: (P) %d - (C) %d", playerScore, computerScore);
        } else {
            return "You exited the game!";
        }

    }

}

int main(void){
    printf("Welcome to the game!\n\nIf you wish to exit the game, type \"exit\"");
    //printf(computerPlay());

    //printf(userPlay());
    printf(gamePlay());

    return 0;
}

