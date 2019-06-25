// Problem: http://140.114.86.238/problem/10954/
#include <stdio.h>

int i;
char array[100];

int evalBoolExpr(int a, int b, int cc, int d)
{
    i++;
    
    char op1, op2;
    
    if (array[i] == '&')
    {
        op1 = evalBoolExpr(a, b, cc, d);
        op2 = evalBoolExpr(a, b, cc, d);
        return op1 & op2;
    } else if (array[i] == '|')
    {
        op1 = evalBoolExpr(a, b, cc, d);
        op2 = evalBoolExpr(a, b, cc, d);
        return op1 | op2;
    } else if (array[i] == 'A') {
        return a;
    } else if (array[i] == 'B') {
        return b;
    } else if (array[i] == 'C') {
        return cc;
    } else if (array[i] == 'D') {
        return d;
    }
    
    return -1;
}

int main()
{
    scanf("%s", array);
    
    int a, b, c, d;
    
    for (a = 0; a < 2; a++)
    {
        for (b = 0; b < 2; b++)
        {
            for (c = 0; c < 2; c++)
            {
                for (d = 0; d < 2; d++)
                {
                    i = -1;
                    int output = evalBoolExpr(a, b, c, d);
                    printf("%d %d %d %d %d\n", a, b, c, d, output);
                }
            }
        }
    }
    
    
    return 0;
}

