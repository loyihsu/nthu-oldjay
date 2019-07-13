// Problem: http://140.114.86.238/problem/10875/
#include <stdio.h>
#include <stdlib.h>
#include "function.h"

void sortArray(int R, int (*array)[COLUMN]) {
    int i, j, k, temp;
    
    for (i = 0; i < R-1; i++) {
        for (j = 0; j < R-1-i; j++) {
            for (k = 0; k<COLUMN; k++) {
                if (array[j][k] > array[j+1][k]) {
                    temp = array[j][k];
                    array[j][k] = array[j+1][k];
                    array[j+1][k] = temp;
                }
            }
        }
    }
}
