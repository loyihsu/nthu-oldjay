// Problem: http://140.114.86.238/problem/10759/
#include <stdio.h>

int main(void) {
    int size, i, j, temp;
    
    scanf("%d", &size);
    
    int output[size][size];
    
    for (i = 0; i < size; i++)
        for (j = 0; j < size; j++)
            scanf("%d", &output[i][j]);
    
    for (i = 0; i < size; i++) {
        for (j = 0; j < size; j++) {
            scanf("%d", &temp);
            if (temp < output[i][j])
                output[i][j] = temp;
            printf("%d", output[i][j]);
            if (j != size - 1)
                printf(" ");
        }
        printf("\n");
    }
    
    return 0;
}
