// Problem: http://140.114.86.238/problem/10806/
#include <stdio.h>
#include "function.h"

int numPrime(int start, int end)
{
    int i, j, count = 0, pint = 0;
    for (i = start; i<=end; i++)
    {
        if (i < 2)
        {
            continue;
        }
        for (j = 2; j < i; j++)
        {
            if (i % j == 0)
            {
                pint++; //able to be divided
            }
        }
        if (pint == 0) //unable to be divided
        {
            count++;
        }
        pint = 0;
    }
    return count;
}
