#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DB_SIZE 235
#define BUFF_SIZE 10

void remove_newline(char *s) {
    for (int i = 0; i < BUFF_SIZE; i++) {
        if (s[i] == '\n') {
            s[i] = '\0';
        }
    }
}
int comp(const void *a, const void *b) {
return (*(int *)b - *(int *)a);     // a - b will ascend the list(low-high), b - a will descend the list(high-low).
}

int main () {
    
    FILE *file;
    if ((file = fopen("inputs/input1.txt", "r")) == NULL) {
        printf("Unale to read file.\n");
        return -1;
    }

    int *elves_calorie_ct;
    if ((elves_calorie_ct = malloc(DB_SIZE*sizeof(int))) == NULL) {
        printf("Error. Malloc failed.\n");
        return -1;
    }

    char buff[BUFF_SIZE];
    memset(elves_calorie_ct, 0, DB_SIZE*sizeof(int));
    memset(buff, 0, BUFF_SIZE*sizeof(char));

    int indx = 0;
    int highest = 0;
    int calorie_ct = 0;
    int new_line_ct = 0;
    
    while (fgets(buff, BUFF_SIZE, file) != NULL) {
        if (buff[0] == '\n') {
            elves_calorie_ct[indx++] = calorie_ct;
            calorie_ct = 0;
            continue;
        }
        remove_newline(&buff[0]);
        calorie_ct += atoi(&buff[0]);
    }
    
    for (int i = 0; i < DB_SIZE; i++) {
        if (elves_calorie_ct[i] > highest) {
            highest = elves_calorie_ct[i];
        }
    }

    printf("Part 1 answer: %i\n", highest);

    qsort(elves_calorie_ct, DB_SIZE, sizeof(elves_calorie_ct[0]), comp); // Apparently C does have a sort.

    highest = elves_calorie_ct[0];
    highest += elves_calorie_ct[1];
    highest += elves_calorie_ct[2];

    printf("Part 2 answer: %i\n", highest);
    free(elves_calorie_ct);
    return 0;
}