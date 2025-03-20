#include <stdio.h>
#include <stdlib.h>



int main() {
    FILE *file;
    if ((file = fopen("inputs/input4.txt", "r")) == NULL) {
        printf("Unable to open file.\n");
        return -1;
    }
    int elf1[2];
    int elf2[2];
    int overlap = 0;
    int enclosed = 0;
    while (fscanf(file, "%i-%i,%i-%i\n", &elf1[0], &elf1[1], &elf2[0], &elf2[1]) != EOF) {
        if (elf1[0] >= elf2[0] && elf1[1] <= elf2[1] ||
            elf2[0] >= elf1[0] && elf2[1] <= elf1[1]) {
                enclosed++;
        }
    }
    printf("Part 1 answer: %i\n", enclosed);
}