// Problem: http://140.114.86.238/problem/11099/
#include <stdio.h>

int main(void) {
    int x, y, z;

    scanf("%d%d%d", &x, &y, &z);    
    printf("%d %d %d\n", (x+z-y)/2, (x+y-z)/2, (y+z-x)/2);
    
    return 0;
}