// Problem: http://140.114.86.238/problem/10839/
#include <stdio.h>
#include "function.h"

void execInst(int *ptrArr[], char inst, int param1, int param2)
{
    if (inst == 'P')
    {
        ptrArr[param1] = ptrArr[param2];
    } else if (inst == 'S')
    {
        *ptrArr[param1] = param2;
    }
}
