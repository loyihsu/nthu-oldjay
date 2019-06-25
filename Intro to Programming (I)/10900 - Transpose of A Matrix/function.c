// Problem: http://140.114.86.238/problem/10900/
#include <stdio.h>
//#include <stdlib.h>
#include "function.h"

int** allocateMat(int x, int y)
{
    int **a;
    int i;
    
    a = (int**)malloc(x*sizeof(int*));  //an array of array
    for (i = 0; i<x; i++) a[i] = (int*)malloc(y*sizeof(int));   //assign an array to each array
    
    return a;
}

void readInput(int** mat, int m, int n)
{
    int i, j;
    for (i = 0; i < m; i++)
    {
        for (j = 0; j < n; j++)
        {
            scanf("%d", &mat[i][j]);
        }
    }
}

void printResult(int** mat, int m, int n)
{
    int i, j;
    for (i = 0; i<n; i++)
    {
        for (j = 0; j<m; j++)
        {
            printf("%d ", mat[j][i]);
        }
        printf("\n");
    }
    
    return;
}
