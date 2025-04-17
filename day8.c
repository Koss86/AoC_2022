#include <stdio.h>
#include <stdlib.h>

#define NUM_ROWS 99

typedef struct Field {
  int row[NUM_ROWS];
} Field;

int main(void) {
  FILE *file;
  if ((file = fopen("inputs/input8.txt", "r")) == NULL) {
    printf("Unable to open file.\n");
    return -1;
  }
  Field *field;
  if ((field = malloc(sizeof(Field) * NUM_ROWS)) == NULL) {
    printf("Malloc failed.\n");
    return -1;
  }

  char c = 0;
  int indx1 = 0;
  int indx2 = 0;

  while ((c = fgetc(file)) != EOF) {
    if (c != '\0' && c != '\n') {
      // Place ints into struct until end of string.
      field[indx1].row[indx2++] = atoi(&c);
    } else if (c == '\n') {
      // continue here so indx1 doesn't get incremented twice.
      continue;
    } else {
      // Increment indx1 to go to next row,
      // reset indx2 to start at beginning of next row.
      indx1++;
      indx2 = 0;
    }
  }

  for (int i = 0; i < NUM_ROWS; i++) {
    for (int j = 0; j < NUM_ROWS; j++) {
      printf("%d", field[i].row[j]);
    }
    printf("\n");
  }

  return 0;
}
