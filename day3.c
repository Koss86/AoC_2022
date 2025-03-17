#include <stdio.h>
#include <stdlib.h>
#include <string.h>



int main() {
    FILE *file;
    if ((file = "inputs/input3.txt") == NULL) {
        printf("Unable to open file.\n");
        return -1;
    }
    char *buff;
    if ((buff = malloc(50*sizeof(char))) == NULL) {
        printf("Error. Malloc failed.\n");
        return -1;
    }
    memset(buff, 0, 50*sizeof(char));

    while (fscanf(file, "%s\n", buff != EOF)) {
        
    }

    return 0;
}