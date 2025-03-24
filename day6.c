#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFF_SIZE 4096

bool are_unique(char *s);

int main() {
    FILE *file;
    if ((file = fopen("inputs/input6.txt", "r")) == NULL) {
        printf("Unable to open file.\n");
        return -1;
    }
    char *buff; 
    if ((buff = malloc(BUFF_SIZE*sizeof(char))) == NULL) {
        printf("Malloc failed.\n");
 
    }
    char *s;
    if ((s = malloc(15*sizeof(char))) == NULL) {
        printf("Malloc failed.\n");
        return -1;
    }
    char c;
    int indx = 0;

    while ((c = fgetc(file)) != EOF) { buff[indx++] = c; }
    
    int leng = strlen(buff);

    for (int i = 0; i < leng-1; i++) {
        strncpy(s, &buff[i], 4);
        if (are_unique(s)) {
            printf("Part 1 answer: %i\n", i+4);
            break;
        }
    }


    for (int i = 0; i < leng-1; i++) {
        strncpy(s, buff+i, 14);
        if (are_unique(s)) {
            printf("Part 2 answer: %i\n", i+14);
            break;
        }
    }

    return 0;
}

bool are_unique(char *s) {
    int leng = strlen(s);
    for (int i = 0; i < leng-1; i++) {
        char c1 = s[i];
        for (int j = i+1; j < leng; j++) {
            char c2 = s[j];
            if (c1 == c2) {
                return false;
            }
        }
    }
    return true;
}