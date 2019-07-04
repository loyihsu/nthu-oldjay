// Problem: http://140.114.86.238/problem/10768/
#include <stdio.h>

int main(void) {
    char c;
    int size, times, i, j, k;
    
    scanf("%c%d%d", &c, &size, &times);
    
    for (k = 0; k < times; k++) {
        for (i = 0; i < size; i++) {
            for (j = 0; j <= i; j++)
                printf("%c", c);
            if (!(size == 1 && k == times - 1))
                printf("\n");
        }
        for (i = size-1; i > 1; i--) {
            for (j = i-1; j >= 0; j--)
                printf("%c", c);
            printf("\n");
        }
    }
    if (size != 1)
        printf("%c", c);
    
    return 0;
}
