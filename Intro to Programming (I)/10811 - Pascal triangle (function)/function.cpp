// Problem: http://140.114.86.238/problem/10811/

#include <stdio.h>
#include "function.h"

void pascalNum(int n) {
    if (n != 0) {
        int i, j;
        int array[100][100] = {0};
        
        for (i = 1; i < 100; i++) {     // All the 1's
            array[i][1] = 1;
            array[i][i] = 1;
        }
        for (i = 2; i < 100; i++)
            for (j = 2; j < i; j++)
                array[i][j] = array[i-1][j-1]+array[i-1][j];    // Deal with the inside numbers
        
        for (i = 1; i <= n+1; i++)
            printf("%6d", array[n+1][i]);
        
        printf("\n");
    }
}
