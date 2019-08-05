// Problem: http://140.114.86.238/problem/10766/
#include <stdio.h>

int main(void) {
    int balls[5] = {0, 1, 2, 3, 4}, a, b, temp, i;
    
    scanf("%d",&i);
    while (i--) {
        scanf("%d%d", &a, &b);
        
        temp = balls[a];
        balls[a] = balls[b];
        balls[b] = temp;
    }
    printf("%d %d %d %d %d", balls[0], balls[1], balls[2], balls[3], balls[4]);
    
    return 0;
}
