// Problem: http://140.114.86.238/problem/10099/
#include <stdio.h>

int main(void)
{
    int n, i, j;
    
    scanf("%d", &n);
    
    int elements[n];
    
    for (i = 0; i < n; i++)
        scanf("%d", &elements[i]);
    
    for (i = 0; i < n ; i++) {
        for (j = 0; j < n; j++) {
            int pos = (i-j < 0) ? i-j+n : i-j;
            printf("%2d", elements[pos]);
        }
        printf("\n");
    }
    
    return 0;
}