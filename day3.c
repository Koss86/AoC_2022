#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFF_SIZE 60

void split_string_mid(int, char *, char *);
int main() {
    FILE *file;
    if ((file = fopen("inputs/input3.txt", "r")) == NULL) {
        printf("Unable to open file.\n");
        return -1;
    }
    char *buff1;
    if ((buff1 = malloc(BUFF_SIZE * sizeof(char))) == NULL) {
        printf("Error. Malloc failed.\n");
        return -1;
    }
    char *buff2;
    if ((buff2 = malloc((BUFF_SIZE/2) * sizeof(char))) == NULL) {
        printf("Error. Malloc failed.\n");
        return -1;
    }
    memset(buff1, 0, BUFF_SIZE * sizeof(char));

    memset(buff2, 0, (BUFF_SIZE/2) * sizeof(char));
    while (fscanf(file, "%s\n", buff1) != EOF) {
        int leng = strlen(buff1);
        split_string_mid(leng, buff1, buff2);
        printf("%s\n%s\n", buff1, buff2);
    }
    
    free(buff1); free(buff2);
    return 0;
}

void split_string_mid(int leng, char *s1, char *s2) {
    for (int i = 0, j = leng/2; j < leng; i++, j++) {
        s2[i] = s1[j];
        s2[i+1] = '\0';
    }
    s1[leng/2] = '\0';
}
