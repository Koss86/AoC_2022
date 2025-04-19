#include <stdio.h>

int main() {
  FILE *file;
  if ((file = fopen("inputs/input8.txt", "r")) == NULL) {
    printf("Unable to open file.\n");
    return -1;
  }

  char c;
  int line_num = 1;
  printf("%d: ", line_num++);
  while ((c = fgetc(file)) != EOF) {
    printf("%c", c);
    if (c == '\n') {
      printf("%d: ", line_num++);
    }
  }
}
