#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>

int randomNum(int lowerLimit, int upperLimit){
    srand(time(NULL));
    int random =  lowerLimit + rand() % (upperLimit - lowerLimit);
    return random;
}

char* computerPlay(){
    int computerValue;

    computerValue = randomNum(1, 100);

    if (computerValue <= 33) {
        return "Rock";
    } else if (computerValue <= 66) {
        return "Scissor";
    } else {
        return "Paper";
    }
}

int userPlay(){
    char userInput[20];

    scanf("\n%s", userInput);
    if (!strcmp(userInput, "Rock")) {
        return 1;
    } else if (!strcmp(userInput, "Paper")) {
        return 2;
    } else if (!strcmp(userInput, "Scissor")) {
        return 3;
    } else {
        return 4;
    }
}

char* gameOutcome(){
    char* computerOutput;
    int userOutput;

    userOutput = userPlay();
    computerOutput = computerPlay();


    if (!strcmp(computerOutput, "Rock") == userOutput) {
        return "\nComputer chose Rock";
    } else if (!strcmp(computerOutput, "Paper")) {
        return "\nComputer chose Paper";
    } else if (!strcmp(computerOutput, "Scissor")) {
        return "\nComputer chose Scissor";
    } else {
        return "NULL";
    }

}

int main(void){
    printf("Hello World!\n");
    //printf(computerPlay());
    printf("\nChoose rock, paper or scissor: ");
    //printf(userPlay());
    printf(gameOutcome());

    return 0;
}

