#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DB_SIZE 2500
#define ROCK 'A'
#define PAPER 'B'
#define SCISSORS 'C'
#define P_ROCK 'X' 
#define P_PAPER 'Y' 
#define P_SCISSORS 'Z'

int main () {
    FILE *file;
    if ((file = fopen("inputs/input2.txt", "r")) == NULL) {
        printf("Unable to read file.\n");
        return -1;
    }
    //  1 = ROCK 2 = PAPER 3 = SCISSORS
    //  0 = Lost 3 = DRAW  6 = WON

    int score = 0;
    char opponent, player;

    while (fscanf(file, "%c %c\n", &opponent, &player) != EOF) {
        if (opponent == ROCK) {
            if (player == P_ROCK) {
                score += 4;
            } else if (player == P_PAPER) {
                score += 8;
            } else {
                score += 3;
            }
        } else if (opponent == PAPER) {
            if (player == P_ROCK) {
                score += 1;
            } else if (player == P_PAPER) {
                score += 5;
            } else {
                score += 9;
            }
        } else {
            if (player == P_ROCK) {
                score += 7;
            } else if (player == P_PAPER) {
                score += 2;
            } else {
                score += 6;
            }
        }
    }
    printf("Part 1 answer: %i\n", score);
    return 0;
}