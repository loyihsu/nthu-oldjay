// Problem: http://140.114.86.238/problem/10824/
#include <stdio.h>
#include "function.h"

void hanoi(int n, char A, char B, char C)
{
    //move the top disc from A to C
    if (n == 1)
    {
        printf("%d\n", n);
        return;
    }
    
    //move the top discs from A to B
    hanoi(n-1, A, B, C);
    
    //move the last disc from A to C
    printf("%d\n", n);
    
    //move the n-1 discs from B to C
    hanoi(n-1, B, C, A);
}
