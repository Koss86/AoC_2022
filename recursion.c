#include <stdio.h>
#include <stdlib.h>

void draw(int n) {

    if (n <= 0) {
        return;
    }
    draw(n-1);
    
    for (int i = 0; i < n; i++) {
        printf("#");
    }
    printf("\n");
}

int main() {
    int h;
    printf("Height: ");
    scanf("%i", &h);
    draw(h);
}