#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct File {
  char *name;
  int size;
  struct Dir *file_parent;
} File;

typedef struct Dir {
  char *name;
  int size;
  File *files[100];
  struct Dir *dir_parent;
} Dir;

typedef struct Filesystem {
  struct Dir dir[210];
} Filesystem;

int main() {
  FILE *file;
  if ((file = fopen("inputs/input7.txt", "r")) == NULL) {
    printf("Unable to open file.\n");
    return -1;
  }
  Filesystem *filesystem;
  if ((filesystem = malloc(sizeof(Filesystem))) == NULL) {
    printf("Error. Malloc failed for Filesystem.\n");
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
    }
  }

  fclose(file);
  free(filesystem);
  return 0;
}
