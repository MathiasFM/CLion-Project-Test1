#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int randomNum(int lowerLimit, int upperLimit){
    srand(time(NULL));
    int random =  lowerLimit + rand() % (upperLimit - lowerLimit);
    return random;
}

char* computerPlay(){
    int computerValue;

    computerValue = randomNum(1, 100);

    if (computerValue <= 33) {
        printf("Rock");
    } else if (computerValue <= 66) {
        printf("Scissor");
    } else {
        printf("Paper");
    }

    return 0;
}

char* userPlay(){
    char userInput[20];

    scanf("\n%s", userInput);
    printf("You chose %s", userInput);

    return 0;
}

int main(void){
    printf("Hello World!\n");
    printf(computerPlay());
    printf("\nChoose rock, paper or scissor: ");
    printf("%s", userPlay());

    return 0;
}

