// Problem: http://140.114.86.238/problem/10832/
#include<stdio.h>
#include"function.h"

void showResult(int n) {
    int i;

    printf("(%d", numbers[0]);
    for (i = 1; i<n; i++) {
        printf(",%d", numbers[i]);
    }
    printf(")\n");
}

void filling(int amount, int cur, int n) {
    int i;
    
    if (cur == n) {
        if (amount == 0) showResult(cur); // Print only if the water is all poured
    } else if (amount >= liters[cur]) {
        for (i = amount/liters[cur]; i >= 0; i--) {
            numbers[cur] = i;       // Start from the most -> 0 of containers
            filling(amount - numbers[cur] * liters[cur], cur+1, n); // See how it works
        }
    } else {
        // No enough water, iterate
        filling(amount-numbers[cur]*liters[cur], cur+1, n);
    }
}