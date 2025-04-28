#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Dir {
  char *name;
  struct Dir *parent;
} Dir;

typedef struct Filesystem {
  struct Dir dirs[210];
} Filesystem;

int main() {
  FILE *file;
  if ((file = fopen("inputs/input7.txt", "r")) == NULL) {
    printf("Unable to open file.\n");
    return -1;
  }
  char buffer[32];
  memset(buffer, 0, 32 * sizeof(char));

  int dirs = 0;
  int indx = 0;
  char c;
  while ((c = fgetc(file)) != EOF) {
    if (c != '\n') {
      buffer[indx++] = c;
    } else {
      buffer[indx] = '\0';
      if (buffer[0] == 'd' && buffer[2] == 'r' && buffer[3] == ' ') {
        dirs++;
      }
      indx = 0;
      printf("%s\n", buffer);
    }
  }
  printf("%i\n", dirs);
  return 0;
}
