#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    FILE *file;
    if ((file = fopen("inputs/input7.txt", "r")) == NULL) {
        printf("Unable to open file.\n");
        return -1;
    }
    char buffer[256];
    memset(buffer, 0, 256*sizeof(char)); 
    }
}
