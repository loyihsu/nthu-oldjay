// Problem: http://140.114.86.238/problem/10758/
#include <stdio.h>

int abs(int original) {
    return (original >= 0) ? original : original * (-1);
}

int main(void) {
    int size, start_x, start_y, i, j;
    
    scanf("%d", &size);
    scanf("%d%d", &start_x, &start_y);
    for (i = 0; i < size; i++) {
        for (j = 0; j < size; j++) {
            printf("%3d", abs(i-(start_x-1))+abs(j-(start_y-1)));
        }
        printf("\n");
    }
    
    return 0;
}