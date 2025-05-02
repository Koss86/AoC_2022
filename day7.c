#include <stdio.h>
// #include <stdlib.h>
#include <string.h>

int main() {
  FILE *file;
  if ((file = fopen("inputs/input7.txt", "r")) == NULL) {
    printf("Unable to open file.\n");
    return -1;
  }

  char buffer[32];
  memset(buffer, 0, 32 * sizeof(char));
  int indx = 0;
  char c;

  while ((c = fgetc(file)) != EOF) {
    if (c != '\n') {
      buffer[indx++] = c;
    } else {
      buffer[indx] = '\0';
      indx = 0;
    }
  }

  fclose(file);
  return 0;
}
