// Problem: http://140.114.86.238/problem/10900/
#include <stdio.h>
#include "function.h"

int** allocateMat(int x, int y) {
    int **a, i;
    
    a = (int**)malloc(x*sizeof(int*));
    for (i = 0; i < x; i++)
        a[i] = (int*)malloc(y*sizeof(int));  

    return a;
}

void readInput(int** mat, int m, int n) {
    int i, j;
    for (i = 0; i < m; i++)
        for (j = 0; j < n; j++)
            scanf("%d", &mat[i][j]);
}

void printResult(int** mat, int m, int n) {
    int i, j;
    for (i = 0; i<n; i++) {
        for (j = 0; j<m; j++)
            printf("%d ", mat[j][i]);
        printf("\n");
    }
}
