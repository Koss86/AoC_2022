#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFF_SIZE 4096

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

    char c5, c6, c7, c8, c9, c10,
        c11, c12, c13, c14, c15;

    for (int i = 0; i < leng; i++) {

        if (c1 != c2 && c1 != c3 && c1 != c4 &&
            c1 != c5 && c1 != c6 && c1 != c7 &&
            c1 != c8 && c1 != c9 && c1 != c10 &&
            c1 != c11 && c1 != c12 && c1 != c13 &&
            c1 != c14 && c1 != c15) {

                if (c2 != c3 && c2 != c4 &&
                    c2 != c5 && c2 != c6 && c2 != c7 &&
                    c2 != c8 && c2 != c9 && c2 != c10 &&
                    c2 != c11 && c2 != c12 && c2 != c13 &&
                    c2 != c14 && c2 != c15) {

                        if (c3 != c4 && c3 != c5 && c3 != c6 && 
                            c3 != c7 && c3 != c8 && c3 != c9 && 
                            c3 != c10 && c3 != c11 && c3 != c12 && 
                            c3 != c13 && c3 != c14 && c3 != c15) {

                                if (c4 != c5 && c4 != c6 && 
                                    c4 != c7 && c4 != c8 && c4 != c9 && 
                                    c4 != c10 && c4 != c11 && c4 != c12 && 
                                    c4 != c13 && c4 != c14 && c4 != c15) {

                                        if (c5 != c6 && c5 != c7 && c5 != c8 && c5 != c9 && 
                                            c5 != c10 && c5 != c11 && c5 != c12 && 
                                            c5 != c13 && c5 != c14 && c5 != c15) {

                                                if (c6 != c7 && c6 != c8 && c6 != c9 && 
                                                    c6 != c10 && c6 != c11 && c6 != c12 && 
                                                    c6 != c13 && c6 != c14 && c6 != c15) {

                                                        if ( c7 != c8 && c7 != c9 && 
                                                            c7 != c10 && c7 != c11 && c7 != c12 && 
                                                            c7 != c13 && c7 != c14 && c7 != c15) {

                                                                if (c8 != c9 && c8 != c10 && c8 != c11 && c8 != c12 && 
                                                                    c8 != c13 && c8 != c14 && c8 != c15) {

                                                                        if (c9 != c10 && c9 != c11 && c9 != c12 && 
                                                                            c9 != c13 && c9 != c14 && c9 != c15) {

                                                                                if ( c10 != c11 && c10 != c12 && 
                                                                                    c10 != c13 && c10 != c14 &&
                                                                                    c10 != c15) {

                                                                                        if (c11 != c12 && c11 != c13 &&
                                                                                            c11 != c14 && c11 != c15) {

                                                                                                if (c12 != c13 && c12 != c14 && c12 != c15) {

                                                                                                    if (c13 != c14 && c13 != c15) {

                                                                                                        if (c14 != c15) {
                                                                                                            printf("Part 2 answer: %i\n", i+14);
                                                                                                        }
                                                                                                    }
                                                                                                }
                                                                                            }
                                                                                    }
                                                                            }
                                                                    }
                                                            }
                                                    }
                                            }
                                    }
                            }
                    }
            }
    }

    return 0;
}