// Problem: http://140.114.86.238/problem/10728/
#include <stdio.h>

int main(void) {
    int n, x, y, z;

    scanf("%d%d%d%d", &n, &x, &y, &z);
    printf("%d %d", x+y-n+z, n-y-z);

    return 0;
}