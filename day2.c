#include <stdio.h>
#include <string.h>

#define DB_SIZE 2500
#define ROCK 'A'
#define PAPER 'B'
#define ROCK_P 'X'
#define PAPER_P 'Y'

int main() {
  FILE *file;
  if ((file = fopen("inputs/input2.txt", "r")) == NULL) {
    printf("Unable to read file.\n");
    return -1;
  }

  int score1 = 0;
  int score2 = 0;
  char opponent, player;

  while (fscanf(file, "%c %c\n", &opponent, &player) != EOF) {
    if (opponent == ROCK) {
      if (player == ROCK_P) {
        score1 += 4;
        score2 += 3;
      } else if (player == PAPER_P) {
        score1 += 8;
        score2 += 4;
      } else {
        score1 += 3;
        score2 += 8;
      }
    } else if (opponent == PAPER) {
      if (player == ROCK_P) {
        score1 += 1;
        score2 += 1;
      } else if (player == PAPER_P) {
        score1 += 5;
        score2 += 5;
      } else {
        score1 += 9;
        score2 += 9;
      }
    } else {
      if (player == ROCK_P) {
        score1 += 7;
        score2 += 2;
      } else if (player == PAPER_P) {
        score1 += 2;
        score2 += 6;
      } else {
        score1 += 6;
        score2 += 7;
      }
    }
  }
  printf("Part 1 answer: %i\n", score1);
  printf("Part 2 answer: %i\n", score2);
  return 0;
}
