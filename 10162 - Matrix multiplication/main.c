// Problem: http://140.114.86.238/problem/10162/
#include <stdio.h>

int main(void)
{
    int i, j, k;
    int ai, aj, bi, bj;
    int a[11][11];
    int b[11][11];
    int output[11][11];
    int sum = 0;
    
    scanf("%d%d", &ai, &aj);
    
    for (i = 0; i<ai; i++)
    {
        for (j = 0; j<aj; j++)
        {
            scanf("%d", &a[i][j]);
        }
    }
    
    scanf("%d%d", &bi, &bj);
    
    for (i = 0; i<bi; i++)
    {
        for (j = 0; j<bj; j++)
        {
            scanf("%d", &b[i][j]);
        }
    }
    
    for (i = 0; i<ai; i++)
    {
        for (j = 0; j<bj; j++)
        {
            for (k = 0; k<bi; k++)
            {
                sum = sum + a[i][k]*b[k][j];
            }
            output[i][j] = sum;
            sum = 0;
        }
    }
    
    for (i = 0; i<ai; i++)
    {
        for (j = 0; j<bj; j++)
        {
            printf("%d ", output[i][j]);
            /*if (j!=bj-1)
             {
             printf(" ");
             }*/
        }
        printf("\n");
    }
    return 0;
}
