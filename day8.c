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
      // Place tree height into relative col index, then increment indx2, until
      // end of line.
      row[indx1].col[indx2++] = atoi(&c);
    } else if (c == '\n') {
      indx1++;   // Icrement indx1 to move to next row,
      indx2 = 0; // and reset indx2 to start at beginning of col.
    }
  }
  int boarder_trees = (NUM_ROWS * 2) + (NUM_ROWS - 2) * 2;
  int visable = 0;
  // Start at 1 to skip 1st row/col since it's visable
  // NUM_ROWS-1 to skip last row/col
  for (int i = 1; i < NUM_ROWS - 1; i++) {
    for (int j = 1; j < NUM_ROWS - 1; j++) {
      printf("----searching row %i col %i-----\n%15i\n", i, j, row[i].col[j]);
      if (is_visable(row, i, j) == true) {
        visable++;
      }
    }
  }
  // 499 too low
  printf("Part 1 answer: %d\n", visable + boarder_trees);

  /* // Print each row of nums
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

  // check row to left of tree_size
  for (int i = 0; i < col; i++) {
    if (field[row].col[i] >= tree_size) {
      taller++;
      printf("tree size: %i taller: %i\n", tree_size, field[row].col[i]);
    }
  }

  if (taller == 0) {
    return true; // return true if no trees were found to be taller.
  }
  taller = 0;

  // check row to right of tree_size
  for (int i = col + 1; i < NUM_ROWS; i++) {
    if (field[row].col[i] >= tree_size) {
      taller++;
      printf("tree size: %i taller: %i\n", tree_size, field[row].col[i]);
    }
  }

  if (taller == 0) {
    return true;
  }
  taller = 0;

  // check cols above tree_size
  for (int i = 0; i < row; i++) {
    if (field[i].col[col] >= tree_size) {
      taller++;
      printf("tree size: %i taller: %i\n", tree_size, field[i].col[col]);
    }
  }

  if (taller == 0) {
    return true;
  }
  taller = 0;

  // check cols below tree_size
  for (int i = row + 1; i < NUM_ROWS; i++) {
    if (field[i].col[col] >= tree_size) {
      taller++;
      printf("tree size: %i taller: %i\n", tree_size, field[i].col[col]);
    }
  }

  if (taller == 0) {
    return true;
  }

  return false;
}
