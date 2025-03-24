#include <stdio.h>
#include <stdlib.h>



int main() {
    FILE *file;
    if ((file = fopen("inputs/input7.txt", "r")) == NULL) {
        printf("Unable to open file.\n");
        return -1;
    }
    
}