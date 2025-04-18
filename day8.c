#include <stdio.h>
#include <stdlib.h>

#define NUM_ROWS 99

typedef struct Field {
  int col[NUM_ROWS];
} Field;

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
      // Icrement indx1 to move to next row,
      // and reset indx2 to start at beginning of col.
      indx1++;
      indx2 = 0;
    }
  }

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
