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
  int boarder_trees = (NUM_ROWS * 2) + (NUM_ROWS - 2) * 2;
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
  printf("Part 1 answer: %d\n", visable + boarder_trees);

  int perfect_view = 0;
  for (int i = 0, cur_pv = 0; i < NUM_ROWS; i++) {
    for (int j = 0; j < NUM_ROWS; j++) {
      cur_pv = find_perf_view(row, i, j);
      if (cur_pv > perfect_view) {
        perfect_view = cur_pv;
      }
    }
  }

  printf("Part 2 answer: %d\n", perfect_view);

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
  taller = 0;

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

// 9317154 too high. 161280 not correct.
int find_perf_view(Field *field, int row, int col) {
  int pv = 0;
  int cur_tree = field[row].col[col];
  int left, right, above, below;
  left = right = above = below = 0;

  // check row to left of cur_tree
  for (int i = 0; i < col; i++) {
    if (field[row].col[i] >= cur_tree) {
      left = i;
      break;
    }
  }

  // check row to right of cur_tree
  for (int i = col + 1, ct = 0; i < NUM_ROWS; i++) {
    if (field[row].col[i] >= cur_tree) {
      right = ct;
      break;
    }
    ct++;
  }

  // check cols above cur_tree
  for (int i = 0; i < row; i++) {
    if (row == 0) {
      printf("row is 0\n");
    }
    if (field[i].col[col] >= cur_tree) {
      above = i;
      if (row == 0) {
        printf("above = %i", above);
        printf("\n");
      }
      break;
    }
  }

  // check cols below cur_tree
  for (int i = row + 1, ct = 0; i < NUM_ROWS; i++) {
    if (field[i].col[col] >= cur_tree) {
      below = ct;
      break;
    }
    ct++;
  }

  pv = left * right * above * below;

  return pv;
}
