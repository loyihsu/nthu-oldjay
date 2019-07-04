// Problem: http://140.114.86.238/problem/10806/
#include <stdio.h>
#include "function.h"

int numPrime(int start, int end) {
    int i, j, count = 0, divs = 0;
    
    for (i = start; i <= end; i++) {
        // Scan in the range
        if (i < 2) continue;           // Skip 1
        for (j = 2; j < i; j++) {
            if (i % j == 0) {          // Div found
                divs++;
                break;
            }
        }
        if (!divs) count++;            // Nothing found!
        divs = 0;
    }

    return count;
}
