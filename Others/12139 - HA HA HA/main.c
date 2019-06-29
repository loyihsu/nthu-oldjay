// Problem: http://140.114.86.238/problem/12139/
#include <stdio.h>

int gcd(int a, int b) {
    return (b == 0) ? a : gcd(b, a%b);
}

int main(void) {
    int n, i, j;
    
    scanf("%d", &n);
    
    int a[n], max=0;
    
    for (i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            if (i != j) {
                int cur = gcd(a[i],a[j]);
                if (cur > max)
                    max = cur;
            }
        }
    }
    printf("%d\n", max);
    
    return 0;
}