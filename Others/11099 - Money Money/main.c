// Problem: http://140.114.86.238/problem/11099/
#include <stdio.h>

int main(void) {
    int x, y, z;
    
    scanf("%d%d%d", &x, &y, &z);
    
    int jay   = (x + z - y)/2;
    int jolin = (x + y - z)/2;
    int jj    = (y + z - x)/2;
    
    printf("%d %d %d\n", jay, jolin, jj);
    
    return 0;
}
