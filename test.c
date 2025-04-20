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

  int line_num = 0;
  while ((c = fgetc(file)) != EOF) {
    printf("%c", c);
    if (c == '\n') {
      printf("%d: ", line_num++);
    }
  }

  return 0;
}
