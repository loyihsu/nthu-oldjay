// Problem: http://140.114.86.238/problem/12135/
#include <stdio.h>

int main(void) {
    int n, k, i, j;
    
    scanf("%d%d", &n, &k);
    
    long long a[n], top, down;
    double maxAver=0, tempAver=0;
    
    scanf("%lld", &a[0]);
    
    for (i = 1; i < n; i++) {
        scanf("%lld", &top);
        a[i] = top + a[i-1];
    }
    
    for (i = k-1; i < n; i++)
    {
        for (j = 0; j < n-i; j++)
        {
            top  = a[i+j];
            down = (j-1 >= 0) ? a[j-1] : 0;
            
            tempAver = top - down;
            tempAver = tempAver/(i+1);
            
            maxAver = (tempAver > maxAver) ? tempAver : maxAver;
        }
    }
    
    printf("%.3lf\n", maxAver);
    
    return 0;
}
