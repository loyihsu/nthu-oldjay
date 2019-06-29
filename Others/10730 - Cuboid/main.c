// Problem: http://140.114.86.238/problem/10730/
#include <stdio.h>

int main(void) {
    int length, width, height;
    
    scanf("%d%d%d", &length, &width, &height);
    printf("%d %d",length*width*height, (length*width+width*height+length*height)*2);
    
    return 0;
}