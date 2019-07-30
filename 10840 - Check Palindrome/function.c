// Problem: http://140.114.86.238/problem/10840/
#include <stdio.h>
#include <string.h>
#include "function.h"

int isPalindrome(char *start, char *end)
{
    int i, flag = 1;
    unsigned long half = (strlen(start))/2;
    
    for (i = 0; i <= half; i++)
        flag = (start[i] == end[-i] && flag == 1) ? 1 : 0;
    
    return flag;
}
