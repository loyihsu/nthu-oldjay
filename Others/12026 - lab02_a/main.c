// Problem: http://140.114.86.238/problem/12026/
#include <stdio.h>

int main(void) {
    int sequence[9], book[9], i, sum;
    
    for (i = 0; i < 9; i++) {
        scanf("%d", &sequence[i]);
        book[i] = 0;
    }
    i = sequence[0]-1;
    sum = 0;
    while (book[i] != 1) {
        book[i] = 1;
        sum += sequence[i];
        i = sequence[i]-1;
    }
    printf("%d\n", sum);
    
    return 0;
}