// Problem: http://140.114.86.238/problem/10099/
#include <stdio.h>

int main(void)
{
    int size;
    int i, j;
    int max[30];
    int output[30][30];
    
    
    //stdin
    scanf("%d", &size);
    
    for (i = 0; i < size; i++)
    {
        scanf("%d", &max[i]);
    }
    
    
    //process lower
    for (i = 0; i < size; i++)
    {
        for (j = 0; j < size; j++)
        {
            output[i+j][i] = max[j];
        }
    }
    
    //process upper
    for (i = 0; i < size; i++)
    {
        for (j = 0; j < size; j++)
        {
            if (-size+i+j < 0)
            {
                continue;
            }
            output[-size+i+j][i] = max[j];
        }
    }
    
    //print
    for (i = 0; i < size; i++)
    {
        for (j = 0; j < size; j++)
        {
            printf("%2d", output[i][j]);
        }
        printf("\n");
    }
    return 0;
}
