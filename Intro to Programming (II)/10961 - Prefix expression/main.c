// Problem: http://140.114.86.238/problem/10961/
#include <stdio.h>
#include <stdlib.h>

int EXPR();

int main(void)
{
    int output;
    
    output = EXPR();
    
    printf("%d", output);
    
    return 0;
}

int EXPR()
{
    char c = getchar();
    char number[200];
    
    int op1, op2;
    
    if (c == ' ')
    {
        c = getchar();
    }
    
    if (c == '-')
    {
        op1 = EXPR();
        op2 = EXPR();
        return op1 - op2;
    } else if (c == '+')
    {
        op1 = EXPR();
        op2 = EXPR();
        return op1 + op2;
    } else {
        number[0] = c;
        int i = 1;
        while (c != ' ')
        {
            c = getchar();
            number[i] = c;
            i++;
        }
        return atoi(number);
    }
    return -1;
}
