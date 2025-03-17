#include <stdio.h>
#include <stdlib.h>



int main() {
    FILE *file;
    if ((file = "inputs/input4.txt") == NULL) {
        printf("Unable to open file.\n");
        return -1;
    }
}