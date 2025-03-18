#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define BUFF_SIZE 60

void split_even_string(int, char *, char *);
bool char_in_str(char, char *);
int find_priority(char c);

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

    int sum1 = 0;
    while (fscanf(file, "%s\n", buff1) != EOF) {
        int leng = strlen(buff1);
        split_even_string(leng, buff1, buff2);
        leng = leng/2;
        for (int i = 0; i < leng; i++) {
            char tmp = buff1[i];
            if (char_in_str(tmp, buff2) == true) {
                sum1 += find_priority(tmp);
                break;
            }
        }
    }
    printf("Part 1 answer: %i\n", sum1);
    free(buff1); free(buff2);
    return 0;
}
void split_even_string(int leng, char *s1, char *s2) {
    for (int i = 0, j = leng/2; j < leng; i++, j++) {
        s2[i] = s1[j];
        s2[i+1] = '\0';
    }
    s1[leng/2] = '\0';
}
bool char_in_str(char c, char *s) {
    int leng = strlen(s);
    for (int i = 0; i < leng; i++) {
        if (s[i] == c) {
            return true;
        }
    }
    return false;
}
int find_priority(char c) {
    int num;
    if (c >= 'a' && c <= 'z') {
        switch (c) {
            case 'a':
                return 1;
            case 'b':
                return 2;
            case 'c':
                return 3;
            case 'd':
                return 4;
            case 'e':
                return 5;
            case 'f':
                return 6;
            case 'g':
                return 7;
            case 'h':
                return 8;
            case 'i':
                return 9;
            case 'j':
                return 10;
            case 'k':
                return 11;
            case 'l':
                return 12;
            case 'm':
                return 13;
            case 'n':
                return 14;
            case 'o':
                return 15;
            case 'p':
                return 16;
            case 'q':
                return 17;
            case 'r':
                return 18;
            case 's':
                return 19;
            case 't':
                return 20;
            case 'u':
                return 21;
            case 'v':
                return 22;
            case 'w':
                return 23;
            case 'x':
                return 24;
            case 'y':
                return 25;
            case 'z':
                return 26;
        }
    } else {
        switch (c) {
            case 'A':
                return 27;
            case 'B':
                return 28;
            case 'C':
                return 29;
            case 'D':
                return 30;
            case 'E':
                return 31;
            case 'F':
                return 32;
            case 'G':
                return 33;
            case 'H':
                return 34;
            case 'I':
                return 35;
            case 'J':
                return 36;
            case 'K':
                return 37;
            case 'L':
                return 38;
            case 'M':
                return 39;
            case 'N':
                return 40;
            case 'O':
                return 41;
            case 'P':
                return 42;
            case 'Q':
                return 43;
            case 'R':
                return 44;
            case 'S':
                return 45;
            case 'T':
                return 46;
            case 'U':
                return 47;
            case 'V':
                return 48;
            case 'W':
                return 49;
            case 'X':
                return 50;
            case 'Y':
                return 51;
            case 'Z':
                return 52;
        }
    }
}