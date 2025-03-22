#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define STR_LEN 100

void malloc_stacks();
void init_stacks();
void move_boxes(int, char *, char *);
void move_boxes_multi(int amt, char *from, char *to);

char *stack_1, *stack_2, *stack_3, *stack_4, *stack_5,
     *stack_6, *stack_7, *stack_8, *stack_9;

int main() {
    FILE *file;
    if ((file = fopen("inputs/input5.txt", "r")) == NULL) {
        printf("Unable to open file.\n");
        return -1;
    }

    malloc_stacks();
    init_stacks();

    int amt, from, to;
    char *pFrom, *pTo;
    while (fscanf(file, "move %d from %d to %d\n", &amt, &from, &to) != EOF) {
        switch (from) {
            case 1:
                pFrom = stack_1;
                break;
            case 2:
                pFrom = stack_2;
                break;
            case 3:
                pFrom = stack_3;
                break;
            case 4:
                pFrom = stack_4;
                break;
            case 5:
                pFrom = stack_5;
                break;
            case 6:
                pFrom = stack_6;
                break;
            case 7:
                pFrom = stack_7;
                break;
            case 8:
                pFrom = stack_8;
                break;
            case 9:
                pFrom = stack_9;
        }
        switch (to) {
            case 1:
                pTo = stack_1;
                break;
            case 2:
                pTo = stack_2;
                break;
            case 3:
                pTo = stack_3;
                break;
            case 4:
                pTo = stack_4;
                break;
            case 5:
                pTo = stack_5;
                break;
            case 6:
                pTo = stack_6;
                break;
            case 7:
                pTo = stack_7;
                break;
            case 8:
                pTo = stack_8;
                break;
            case 9:
                pTo = stack_9;
        }
        move_boxes(amt, pFrom, pTo); 
    }
    fclose(file);
    printf("Part 1 answer: ");
    int counter = 0;
    for (int i = 0; i < 9; i++) {
        int leng;
        switch (counter) {
            case 0:
            leng = strlen(stack_1);
            printf("%c", stack_1[leng-1]);
            break;
            case 1:
            leng = strlen(stack_2);
            printf("%c", stack_2[leng-1]);
            break;
            case 2:
            leng = strlen(stack_3);
            printf("%c", stack_3[leng-1]);
            break;
            case 3:
            leng = strlen(stack_4);
            printf("%c", stack_4[leng-1]);
            break;
            case 4:
            leng = strlen(stack_5);
            printf("%c", stack_5[leng-1]);
            break;
            case 5:
            leng = strlen(stack_6);
            printf("%c", stack_6[leng-1]);
            break;
            case 6:
            leng = strlen(stack_7);
            printf("%c", stack_7[leng-1]);
            break;
            case 7:
            leng = strlen(stack_8);
            printf("%c", stack_8[leng-1]);
            break;
            case 8:
            leng = strlen(stack_9);
            printf("%c", stack_9[leng-1]);
        }
        counter++;
    }

    init_stacks();
    file = fopen("inputs/input5.txt", "r");
    while (fscanf(file, "move %d from %d to %d\n", &amt, &from, &to) != EOF) {
        switch (from) {
            case 0:
                break;
            case 1:
                pFrom = stack_1;
                break;
            case 2:
                pFrom = stack_2;
                break;
            case 3:
                pFrom = stack_3;
                break;
            case 4:
                pFrom = stack_4;
                break;
            case 5:
                pFrom = stack_5;
                break;
            case 6:
                pFrom = stack_6;
                break;
            case 7:
                pFrom = stack_7;
                break;
            case 8:
                pFrom = stack_8;
                break;
            case 9:
                pFrom = stack_9;
        }
        switch (to) {
            case 0:
                break;
            case 1:
                pTo = stack_1;
                break;
            case 2:
                pTo = stack_2;
                break;
            case 3:
                pTo = stack_3;
                break;
            case 4:
                pTo = stack_4;
                break;
            case 5:
                pTo = stack_5;
                break;
            case 6:
                pTo = stack_6;
                break;
            case 7:
                pTo = stack_7;
                break;
            case 8:
                pTo = stack_8;
                break;
            case 9:
                pTo = stack_9;
        }
        move_boxes_multi(amt, pFrom, pTo); 
    }
    printf("\nPart 2 answer: ");
    counter = 0;
    for (int i = 0; i < 9; i++) {
        int leng;
        switch (counter) {
            case 0:
            leng = strlen(stack_1);
            printf("%c", stack_1[leng-1]);
            break;
            case 1:
            leng = strlen(stack_2);
            printf("%c", stack_2[leng-1]);
            break;
            case 2:
            leng = strlen(stack_3);
            printf("%c", stack_3[leng-1]);
            break;
            case 3:
            leng = strlen(stack_4);
            printf("%c", stack_4[leng-1]);
            break;
            case 4:
            leng = strlen(stack_5);
            printf("%c", stack_5[leng-1]);
            break;
            case 5:
            leng = strlen(stack_6);
            printf("%c", stack_6[leng-1]);
            break;
            case 6:
            leng = strlen(stack_7);
            printf("%c", stack_7[leng-1]);
            break;
            case 7:
            leng = strlen(stack_8);
            printf("%c", stack_8[leng-1]);
            break;
            case 8:
            leng = strlen(stack_9);
            printf("%c", stack_9[leng-1]);
        }
        counter++;
    }
    printf("\n");
    return 0;
}

void move_boxes_multi(int amt, char *from, char *to) {
    int lengF = strlen(from);
    int lengT = strlen(to);
    int startInd = lengF-amt;
    for (int i = 0; i < amt; i++) {
        to[lengT++] = from[startInd];
        from[startInd++] = '\0';
    }
}
void move_boxes(int amt, char* from, char *to) {
    int lengF = strlen(from);
    int lengT = strlen(to);
    for (int i = 0; i < amt; i++) {
        to[lengT++] = from[lengF-1];
        from[lengF-1] = '\0';
        lengF--;
    }
}
void init_stacks() {
    memset(stack_1, 0, STR_LEN*sizeof(char));
    memset(stack_2, 0, STR_LEN*sizeof(char));
    memset(stack_3, 0, STR_LEN*sizeof(char));
    memset(stack_4, 0, STR_LEN*sizeof(char));
    memset(stack_5, 0, STR_LEN*sizeof(char));
    memset(stack_6, 0, STR_LEN*sizeof(char));
    memset(stack_7, 0, STR_LEN*sizeof(char));
    memset(stack_8, 0, STR_LEN*sizeof(char));
    memset(stack_9, 0, STR_LEN*sizeof(char));

    stack_1[0] = 'H';   stack_2[0] = 'T';   stack_3[0] = 'Z';
    stack_1[1] = 'R';   stack_2[1] = 'B';   stack_3[1] = 'L';
    stack_1[2] = 'B';   stack_2[2] = 'M';   stack_3[2] = 'C';
    stack_1[3] = 'D';   stack_2[3] = 'Z';   stack_3[3] = 'H';
    stack_1[4] = 'Z';   stack_2[4] = 'R';   stack_3[4] = 'N';
    stack_1[5] = 'F';                       stack_3[5] = 'S';
    stack_1[6] = 'L';
    stack_1[7] = 'S';

    stack_4[0] = 'S';   stack_5[0] = 'P';   stack_6[0] = 'V';
    stack_4[1] = 'C';   stack_5[1] = 'G';   stack_6[1] = 'J';
    stack_4[2] = 'F';   stack_5[2] = 'H';   stack_6[2] = 'Z';
    stack_4[3] = 'J';   stack_5[3] = 'W';   stack_6[3] = 'G';
                        stack_5[4] = 'R';   stack_6[4] = 'D';
                        stack_5[5] = 'Z';   stack_6[5] = 'N';
                        stack_5[6] = 'B';   stack_6[6] = 'M';
                                            stack_6[7] = 'T';

    stack_7[0] = 'G';   stack_8[0] = 'M';   stack_9[0] = 'M';
    stack_7[1] = 'L';   stack_8[1] = 'Z';   stack_9[1] = 'C';
    stack_7[2] = 'N';   stack_8[2] = 'R';   stack_9[2] = 'L';
    stack_7[3] = 'W';                       stack_9[3] = 'G';
    stack_7[4] = 'F';                       stack_9[4] = 'V';
    stack_7[5] = 'S';                       stack_9[5] = 'R';
    stack_7[6] = 'P';                       stack_9[6] = 'T';
    stack_7[7] = 'Q';
}
void malloc_stacks() {
    if ((stack_1 = malloc(STR_LEN*sizeof(char))) == NULL) {
        printf("Error.\n");
        exit(-1);
    }
    if ((stack_2 = malloc(STR_LEN*sizeof(char))) == NULL) {
        printf("Error.\n");
        exit(-1);
    }
    if ((stack_3 = malloc(STR_LEN*sizeof(char))) == NULL) {
        printf("Error.\n");
        exit(-1);
    }
    if ((stack_4 = malloc(STR_LEN*sizeof(char))) == NULL) {
        printf("Error.\n");
        exit(-1);
    }
    if ((stack_5 = malloc(STR_LEN*sizeof(char))) == NULL) {
        printf("Error.\n");
        exit(-1);
    }
    if ((stack_6 = malloc(STR_LEN*sizeof(char))) == NULL) {
        printf("Error.\n");
        exit(-1);
    }
    if ((stack_7 = malloc(STR_LEN*sizeof(char))) == NULL) {
        printf("Error.\n");
        exit(-1);
    }
    if ((stack_8 = malloc(STR_LEN*sizeof(char))) == NULL) {
        printf("Error.\n");
        exit(-1);
    }
    if ((stack_9 = malloc(STR_LEN*sizeof(char))) == NULL) {
        printf("Error.\n");
        exit(-1);
    }
}   