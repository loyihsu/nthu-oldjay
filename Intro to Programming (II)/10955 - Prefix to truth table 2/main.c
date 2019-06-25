// Problem: http://140.114.86.238/problem/10955/
#include <stdio.h>

char expr[200];
int pos;

int EXPR(int a, int b, int c, int d);

int main(void)
{
    scanf("%s", expr);
    
    int i, j, k, l;
    int output;
    for (i = 0; i < 2; i++)
    {
        for (j = 0; j < 2; j++)
        {
            for (k = 0; k < 2; k++)
            {
                for (l = 0; l < 2; l++)
                {
                    pos = 0;
                    output = EXPR(i, j, k, l);;
                    if (output == 1)
                        printf("%d %d %d %d %d\n", i, j, k, l, output);
                }
            }
        }
    }
    return 0;
}

int EXPR(int a, int b, int c, int d)
{
    char cha = expr[pos++];
    
    int op1, op2;
    
    if (cha == '&')
    {
        op1 = EXPR(a, b, c, d);
        op2 = EXPR(a, b, c, d);
        return op1 && op2;
    } else if (cha == '|')
    {
        op1 = EXPR(a, b, c, d);
        op2 = EXPR(a, b, c, d);
        return op1 || op2;
    } else if (cha == 'A')
    {
        return a;
    } else if (cha == 'B')
    {
        return b;
    } else if (cha == 'C')
    {
        return c;
    } else if (cha == 'D')
    {
        return d;
    }
    return -1;
}
