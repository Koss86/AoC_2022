#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DB_SIZE 2500

int main () {
    FILE *file;
    if ((file = fopen("inputs/input2.txt", "r")) == NULL) {
        printf("Unable to read file.\n");
        return -1;
    }
    
}