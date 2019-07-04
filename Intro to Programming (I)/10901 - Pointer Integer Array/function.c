// Problem: http://140.114.86.238/problem/10901/
#include <stdio.h>
#include <stdlib.h>
#include "function.h"

int** malloc_ptr(int array_size) {
    int **a = (int**)malloc(sizeof(int*)*array_size);
    return a;
}

void malloc_array(int **array, int array_size) {
    *array = (int*)malloc(sizeof(int)*array_size);
    return;
}

void pointer_ptr_to_array(int *array, int **ptr,int N) {
    int i;
    for (i = 0; i<N; i++) *(ptr+i) = &array[(i+1)*i/2];
    return;
}
