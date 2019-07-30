// Problem: http://140.114.86.238/problem/10162/
#include <stdio.h>

int main(void) {
    int i, j, k, height_a, width_a, height_b, width_b, sum = 0;
    
    scanf("%d%d", &height_a, &width_a);
    
    int a[height_a][width_a];
    
    for (i = 0; i < height_a; i++)
        for (j = 0; j < width_a; j++)
            scanf("%d", &a[i][j]);
    
    scanf("%d%d", &height_b, &width_b);
    
    int b[height_b][width_b], output[height_a][width_b];
    
    for (i = 0; i < height_b; i++)
        for (j = 0; j < width_b; j++)
            scanf("%d", &b[i][j]);
    
    for (i = 0; i < height_a; i++) {
        for (j = 0; j < width_b; j++) {
            for (k = 0; k < width_a; k++)
                sum += a[i][k] * b[k][j];
            output[i][j] = sum;
            sum = 0;
        }
    }
    for (i = 0; i < height_a; i++) {
        for (j = 0; j < width_b; j++)
            printf("%d ", output[i][j]);
        printf("\n");
    }
    
    return 0;
}
