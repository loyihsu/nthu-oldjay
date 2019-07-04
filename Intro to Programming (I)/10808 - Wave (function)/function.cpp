// Problem: http://140.114.86.238/problem/10808/
#include <stdio.h>
#include "function.h"

int length_greater_than_one(char c, int length, int n) {
    int i, j, k;

    for (k = 0; k < n; k++) {
        for (i = 0; i < length; i++) {
            for (j = 0; j <= i; j++)
                printf("%c", c);            // Print upper
            printf("\n");
        }
        for (i = length-1; i > 1; i--) {
            for (j = i-1; j >= 0; j--)
                printf("%c", c);            // Print lower
            printf("\n");
        }
    }

    return 0;
}
