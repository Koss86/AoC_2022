#include <stdio.h>
// #include <stdlib.h>
#include <string.h>

typedef struct Dir {
    struct Dir *parent;
    char name[32];
    int numofdirs;
    int sizeofdirs;
    int numoffiles;
    int sizeoffies;
    int dirsize;
    struct Dir **dirlist;
} Dir;

int main() {
    FILE *file;
    if ((file = fopen("inputs/input7.txt", "r")) == NULL) {
        printf("Unable to open file.\n");
        return -1;
    }

    char buffer[1200];
    memset(buffer, 0, 1200 * sizeof(char));
    int indx = 0;
    char c;

    long ct;
    while ((c = fgetc(file)) != EOF) {
        if (c != '\n') {
            buffer[indx++] = c;
        } else {
            buffer[indx] = '\0';
            indx = 0;
        }
        ct++;

    }

printf("%li chars.\n", ct);


    fclose(file);
    return 0;
}
