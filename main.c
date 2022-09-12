#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>

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
    char userInput[20];

    scanf("\n%s", userInput);
    if (!strcmp(userInput, "Rock")) {
        return 1;
    } else if (!strcmp(userInput, "Paper")) {
        return 2;
    } else if (!strcmp(userInput, "Scissor")) {
        return 3;
    } else {
        return 0;
    }
}

char* gameOutcome(){
    int computerOutput;
    int userOutput;

    userOutput = userPlay();
    computerOutput = computerPlay();


    if (computerOutput == userOutput) {
        return "\nIt's a tie";
    } else if (computerOutput == 1 && userOutput == 3) {
        return "\nYou lose computer chose Rock";
    } else if (computerOutput == 2 && userOutput == 1) {
        return "\nYou lose computer chose Paper";
    } else if (computerOutput == 3 && userOutput == 2) {
    return "\nYou lose computer chose Scissor";
    } else if (computerOutput == 1 && userOutput == 2) {
        return "\nYou win computer chose Rock";
    } else if (computerOutput == 2 && userOutput == 3) {
        return "\nYou win computer chose Paper";
    } else if (computerOutput == 3 && userOutput == 1) {
        return "\nYou win computer chose Scissor";
    } else {
        return "NULL";
    }

}

int gamePlay() {
    int i;


}

int main(void){
    printf("Hello World!\n");
    //printf(computerPlay());
    printf("\nChoose Rock, Paper or Scissor: ");
    //printf(userPlay());
    printf(gameOutcome());

    return 0;
}

