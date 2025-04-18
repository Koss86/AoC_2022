#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define NUM_ROWS 99

typedef struct Field {
  int col[NUM_ROWS];
} Field;

bool is_visable(Field *field, int row, int col);

int main(void) {
  FILE *file;
  if ((file = fopen("inputs/input8.txt", "r")) == NULL) {
    printf("Unable to open file.\n");
    return -1;
  }
  Field *row;
  if ((row = malloc(sizeof(Field) * NUM_ROWS)) == NULL) {
    printf("Malloc failed.\n");
    return -1;
  }

  char c = 0;
  int indx1 = 0;
  int indx2 = 0;

  while ((c = fgetc(file)) != EOF) {
    if (c >= '0' && c <= '9') {
      // Place tree height into relative col index until end of line.
      row[indx1].col[indx2++] = atoi(&c);
    } else if (c == '\n') {
      indx1++;   // Icrement indx1 to move to next row,
      indx2 = 0; // and reset indx2 to start at beginning of col.
    }
  }
  int boarder_trees = NUM_ROWS * 4;
  int visable = 0;
  // Start at 1 to skip 1st row since it's visable
  // NUM_ROWS-1 to skip last row
  for (int i = 1; i < NUM_ROWS - 1; i++) {
    for (int j = 1; j < NUM_ROWS - 1; j++) {
      if (is_visable(row, i, j) == true) {
        visable++;
      }
    }
  }

  printf("Part 1 answer: %d\n", visable + boarder_trees);

  /*  // Print each row of nums
    for (int i = 0; i < NUM_ROWS; i++) {
      for (int j = 0; j < NUM_ROWS; j++) {
        printf("%d", row[i].col[j]);
      }
      printf("\n");
    }
  */

  return 0;
}

bool is_visable(Field *field, int row, int col) {
  int taller = 0;
  int tree_size = field[row].col[col];

  // check row
  for (int i = 0; i < NUM_ROWS; i++) {
    if (field[row].col[i] >= tree_size) {
      taller++;
    }
  }
  if ((--taller) == 0) {
    return true;
  }
  taller = 0;

  // check col
  for (int i = 0; i < NUM_ROWS; i++) {
    if (field[i].col[col] >= tree_size) {
      taller++;
    }
  }
  if ((--taller) == 0) {
    return true;
  }
  return false;
}
