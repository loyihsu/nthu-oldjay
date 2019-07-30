// Problem: http://140.114.86.238/problem/10769/
#include <stdio.h>

int main(void) {
    int size, i, j, flag = 0;
    
    scanf("%d", &size);
    
    int matrix[size][size];
    
    for (i = 0; i < size; i++)
        for (j = 0; j < size; j++)
            scanf("%d", &matrix[i][j]);
   
    for (i = 0; i < size*2-1; i++) {
        flag = 0;
        for (j = i; j >= 0; j--) {
            if (j < size && i-j < size)
            {
                if (flag == 0) flag = 1;
                else printf(" ");
                printf("%d", matrix[j][i-j]);
            }
        }
        printf("\n");
    }
    
    return 0;
}