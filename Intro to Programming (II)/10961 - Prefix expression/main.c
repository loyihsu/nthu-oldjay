// Problem: http://140.114.86.238/problem/10961/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int calculator()
{
    int op1, op2;
    char c = getchar();
    if (c == ' ')
    {
        c = getchar();
    }
    
    if (c == '+')
    {
        op1 = calculator();
        op2 = calculator();
        return op1 + op2;
    } else if (c == '-')
    {
        op1 = calculator();
        op2 = calculator();
        return op1-op2;
    } else {
        char d = getchar();
        char e[100];
        memset(e, 0, sizeof(char)*100);
        int ic = c - '0';
        int i = 1;
        
        if (d == ' ')
        {
            return ic;
        } else {
            e[0] = c;
            e[1] = d;
            i = 2;
            while (d != ' ')
            {
                d = getchar();
                e[i] = d;
                i++;
            }
            return atoi(e);
        }
    }
}

int main(void)
{
    int output = calculator();
    
    printf("%d", output);
    
    return 0;
}
