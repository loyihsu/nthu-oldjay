// Problem: http://140.114.86.238/problem/12027/
#include <stdio.h>

int main(void) {
    int n, i, counter;
    double p[4], v[2], target, temp1, temp2;
    
    scanf("%d", &n);
    while(n--)
    {
        v[0] = 1;
        v[1] = 0;
        for (i = 0; i < 4; i++)
            scanf("%lf",&p[i]);
        scanf("%lf", &target);
        counter = 0;
        while (v[0] >= target) {
            temp1 = p[0] * v[0] + p[1] * v[1];
            temp2 = p[2] * v[0] + p[3] * v[1];
            v[0] = temp1;
            v[1] = temp2;
            counter++;
        }
        printf("%d\n", counter);
    }
    
    return 0;
}