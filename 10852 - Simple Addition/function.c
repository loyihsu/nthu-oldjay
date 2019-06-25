// Problem: http://140.114.86.238/problem/10852/
#include <stdio.h>
#include "function.h"

int addition(int *a, int array_num, int *entry[], int *index_to_add, int num_ind)
{
    int output = 0;
    int i;
    for (i = 0; i<num_ind*2; i = i+2)
    {
        output = output + a[50*index_to_add[i]+index_to_add[i+1]] + entry[array_num][50*index_to_add[i]+index_to_add[i+1]];
    }
    return output;
}
