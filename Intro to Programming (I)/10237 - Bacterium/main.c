// Problem: http://140.114.86.238/problem/10237/
#include <stdio.h>

void divide(int cur, int total, int first, int second, int third) {
    if (cur == total) {
        printf("%d\n", first+second+third);
    } else {
        divide(cur+1, total, first+second, first, second);
    }
    return;
}


int main(void) {
    int totalWeeks;

    scanf("%d", &totalWeeks);
    divide(1, totalWeeks, 1, 0, 0);
    
    return 0;
}