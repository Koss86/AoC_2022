#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define NUM_ROWS 99

typedef struct Field {
  int col[NUM_ROWS];
} Field;

bool is_visable(Field *field, int row, int col);
int find_perf_view(Field *field, int row, int col);

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
    if (isdigit(c)) {
      // Place tree height into relative col index, then increment indx2, until
      // end of line (EOL).
      row[indx1].col[indx2++] = c - '0';
    } else if (c == '\n') {
      indx1++;   // At EOL, increment indx1 to move to next row,
      indx2 = 0; // and reset indx2 to start at beginning of col.
    }
  }
  int border_trees = (NUM_ROWS * 2) + (NUM_ROWS - 2) * 2;
  int visable = 0;
  // Start at 1 to skip 1st row/col since it's visable
  // NUM_ROWS-1 to skip last row/col
  for (int i = 1; i < NUM_ROWS - 1; i++) {
    for (int j = 1; j < NUM_ROWS - 1; j++) {
      if (is_visable(row, i, j) == true) {
        visable++;
      }
    }
  }
  // Answer: 1713
  printf("Part 1 answer: %d\n", visable + border_trees);

  int perfect_view = 0;
  for (int i = 7, cur_pv = 0; i < NUM_ROWS - 1; i++) {
    for (int j = 1; j < NUM_ROWS - 1; j++) {
      cur_pv = find_perf_view(row, i, j);
      if (cur_pv > perfect_view) {
        perfect_view = cur_pv;
      }
    }
  }

  // Answer: 268464
  printf("Part 2 answer: %d\n", perfect_view);

  return 0;
}

bool is_visable(Field *field, int row, int col) {
  int taller = 0;
  int cur_tree = field[row].col[col];

  // check row to left of cur_tree
  for (int i = 0; i < col; i++) {
    if (field[row].col[i] >= cur_tree) {
      taller++;
    }
  }

  if (taller == 0) {
    return true; // return true if no trees were found to be taller.
  }
  taller = 0; // reset taller if not true

  // check row to right of cur_tree
  for (int i = col + 1; i < NUM_ROWS; i++) {
    if (field[row].col[i] >= cur_tree) {
      taller++;
    }
  }

  if (taller == 0) {
    return true;
  }
  taller = 0;

  // check cols above cur_tree
  for (int i = 0; i < row; i++) {
    if (field[i].col[col] >= cur_tree) {
      taller++;
    }
  }

  if (taller == 0) {
    return true;
  }
  taller = 0;

  // check cols below cur_tree
  for (int i = row + 1; i < NUM_ROWS; i++) {
    if (field[i].col[col] >= cur_tree) {
      taller++;
    }
  }

  if (taller == 0) {
    return true;
  }

  return false;
}

int find_perf_view(Field *field, int row, int col) {
  int cur_tree = field[row].col[col];
  int left, right, above, below;
  left = right = above = below = 0;

  // check row to left of cur_tree
  // Starting left of cur_tree position and going
  // left until a tree taller or same height
  // is found or edge is hit
  for (int i = col - 1; i >= 0; i--) {
    left++;
    if (field[row].col[i] >= cur_tree) {
      break;
    }
  }

  // check row to right of cur_tree
  for (int i = col + 1; i < NUM_ROWS; i++) {
    right++;
    if (field[row].col[i] >= cur_tree) {
      break;
    }
  }

  // check cols above cur_tree
  for (int i = row - 1; i >= 0; i--) {
    above++;
    if (field[i].col[col] >= cur_tree) {
      break;
    }
  }

  // check cols below cur_tree
  for (int i = row + 1; i < NUM_ROWS; i++) {
    below++;
    if (field[i].col[col] >= cur_tree) {
      break;
    }
  }

  int pv = left * right * above * below;

  return pv;
}
