// Problem: http://140.114.86.238/problem/10840/
#include <stdio.h>
#include <string.h>
#include "function.h"

int isPalindrome(char *start, char *end)
{
    int i;
    int pro = 1;
    for (i = 0; i <= (strlen(start))/2; i++)
    {
        if (start[i] == end[-i])
        {
            if (pro != 0)
            {
                pro = 1;
            }
        } else {
            pro = 0;
        }
    }
    return pro;
}
