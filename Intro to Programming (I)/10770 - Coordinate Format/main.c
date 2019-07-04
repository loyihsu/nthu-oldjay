// Problem: http://140.114.86.238/problem/10770/
#include <stdio.h>

int main(void) {
    int height, width, i, j, temp;
    
    scanf("%d%d", &height, &width);
    
    for (i = 0; i < height; i++) {
        for (j = 0; j < width; j++) {
            scanf("%d", &temp);
            if (temp)
                printf("%d %d %d\n", i, j, temp);
        }
    }
    
    return 0;
}

