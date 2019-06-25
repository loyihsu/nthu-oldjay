// Problem: http://140.114.86.238/problem/10833/

#include <stdio.h>
#include "function.h"

void show(int n)
{
    int i;
    printf("(%c", list[0]);
    for (i=1; i<n; i++) {
        printf(",%c", list[i]);
    }
    printf(")\n");
}

void Swap(int k, int i)
{
    int temp;
    temp = list[k];
    list[k] = list[i];
    list[i] = temp;
}

void Perm(int k, int n)
{
    int i;
    if (k==n)
    {
        show(n);
    } else {
        for (i = k; i<n; i++)
        {
            Swap(k,i);
            Perm(k+1,n);
            Swap(k,i);
        }
    }
}

