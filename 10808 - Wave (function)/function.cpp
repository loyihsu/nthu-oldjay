// Problem: http://140.114.86.238/problem/10808/
#include <stdio.h>
#include "function.h"

int length_greater_than_one(char c, int length, int n)
{
    int i, j, k;
    //print times
    for (k = 0; k < n; k++)
    {
        //print upper
        for (i = 0; i < length; i++)
        {
            for (j = 0; j<=i; j++)
            {
                printf("%c", c);
            }
            printf("\n");
        }
        
        //print lower
        for (i = length-2; i > 0; i--)
        {
            for (j = 0; j<=i; j++)
            {
                printf("%c", c);
            }
            printf("\n");
        }
    }
    
    return 0;
}

