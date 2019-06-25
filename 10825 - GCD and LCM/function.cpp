// Problem: http://140.114.86.238/problem/10825/
#include <stdio.h>
#include "function.h"

int gcd(int a,int b)
{
    int output = 1;
    int i, j;
    int tempi = 1, tempj = 1;
    
    for (i = 2; i < a; i++)
    {
        if (a % i == 0)
        {
            tempi = i;
        }
        for (j = 2; j < b; j++)
        {
            if (b % j == 0)
            {
                tempj = j;
            }
            
            if (tempi == tempj) output = tempi;
        }
    }
    
    return output;
}


int lcm(int a,int b)
{
    int gcd = 1;
    int i, j;
    int tempi = 1, tempj = 1;
    int output = 1;
    
    for (i = 2; i < a; i++)
    {
        if (a % i == 0)
        {
            tempi = i;
        }
        for (j = 2; j < b; j++)
        {
            if (b % j == 0)
            {
                tempj = j;
            }
            
            if (tempi == tempj) gcd = tempi;
        }
    }
    
    output = (a*b)/gcd;
    
    return output;
}

