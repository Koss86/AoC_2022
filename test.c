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
      // Place tree height into relative col index,
      // then increment indx2, until end of line (EOL).
      row[indx1].col[indx2++] = c - '0';
    } else if (c == '\n') {
      indx1++;   // At EOL, increment indx1 to move to next row,
      indx2 = 0; // and reset indx2 to start at beginning of col.
    }
  }

  return 0;
}
