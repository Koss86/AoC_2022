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
    
    char c;
    int indx = 0;

    while ((c = fgetc(file)) != EOF) { buff[indx++] = c; }
    
    char c1, c2, c3, c4;
    int leng = strlen(buff);

    for (int i = 0; i < leng; i++) {
        c1 = buff[i]; c2 = buff[i+1];
        c3 = buff[i+2]; c4 = buff[i+3];

        if (c1 != c2 && c1 != c3 && c1 != c4) {
            if (c2 != c3 && c2 != c4) {
                if (c3 != c4) {
                    printf("Part 1 answer: %i\n", i+4);
                    break;
                }
            }
        } 
    }

    char *s;
    if ((s = malloc(15*sizeof(char))) == NULL) {
        printf("Malloc failed.\n");
        return -1;
    }

    for (int i = 0; i < leng-1; i += 14) {
        strncpy(s, buff+i, 14);
        if (are_unique(s) == true) {
            printf("Part 2 answer: %i\n", i+13);
            break;
        }
    }

    return 0;
}

bool are_unique(char *s) {
    int leng = strlen(s);
    for (int i = 0; i < leng-1; i++) {
        char c1 = s[i];
        for (int j = i+1; j < leng-1; j++) {
            char c2 = s[j];
            if (c1 == c2) {
                return false;
            }
        }
    }
    return true;
}