#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define STR_LEN 100

void malloc_stacks();

char *stack_1, *stack_2, *stack_3, *stack_4, *stack_5,
     *stack_6, *stack_7, *stack_8, *stack_9;

int main() {
    malloc_stacks();
    *stack_1 = "HRBDZFLS";
    *stack_2 = "TBMZR";
    *stack_3 = "ZLCHNS";
    *stack_4 = "SCFJ";
    *stack_5 = "PGHWRZB";
    *stack_6 = "VJZGDNMT";
    *stack_7 = "GLNWFSPQ";
    *stack_8 = "MZR";
    *stack_9 = "MCLGVRT";
    printf("%s\n", stack_5);
}
void malloc_stacks() {
    if ((stack_1 = malloc(STR_LEN*sizeof(char))) == NULL) {
        printf("Error.\n");
        exit(-1);
    } else {
        memset(stack_1, 0, STR_LEN*sizeof(char));
    }
    if ((stack_2 = malloc(STR_LEN*sizeof(char))) == NULL) {
        printf("Error.\n");
        exit(-1);
    } else {
        memset(stack_2, 0, STR_LEN*sizeof(char));
    }
    if ((stack_3 = malloc(STR_LEN*sizeof(char))) == NULL) {
        printf("Error.\n");
        exit(-1);
    } else {
        memset(stack_3, 0, STR_LEN*sizeof(char));
    }
    if ((stack_4 = malloc(STR_LEN*sizeof(char))) == NULL) {
        printf("Error.\n");
        exit(-1);
    } else {
        memset(stack_4, 0, STR_LEN*sizeof(char));
    }
    if ((stack_5 = malloc(STR_LEN*sizeof(char))) == NULL) {
        printf("Error.\n");
        exit(-1);
    } else {
        memset(stack_5, 0, STR_LEN*sizeof(char));
    }
    if ((stack_6 = malloc(STR_LEN*sizeof(char))) == NULL) {
        printf("Error.\n");
        exit(-1);
    } else {
        memset(stack_6, 0, STR_LEN*sizeof(char));
    }
    if ((stack_7 = malloc(STR_LEN*sizeof(char))) == NULL) {
        printf("Error.\n");
        exit(-1);
    } else {
        memset(stack_7, 0, STR_LEN*sizeof(char));
    }
    if ((stack_8 = malloc(STR_LEN*sizeof(char))) == NULL) {
        printf("Error.\n");
        exit(-1);
    } else {
        memset(stack_8, 0, STR_LEN*sizeof(char));
    }
    if ((stack_9 = malloc(STR_LEN*sizeof(char))) == NULL) {
        printf("Error.\n");
        exit(-1);
    } else {
        memset(stack_9, 0, STR_LEN*sizeof(char));
    }
}