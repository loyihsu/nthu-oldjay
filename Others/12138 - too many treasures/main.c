// Problem: http://140.114.86.238/problem/12138/
#include <stdio.h>

int main(void) {
    long long int n, q, i, l, r, m, output, negativePoint=-1;

    scanf("%lld%lld", &n, &q);
    
    long long int treats[n], temp;

    for (i = 0; i < n; i++)
    {
        scanf("%lld", &temp);
        if (temp < 0 && negativePoint < 0)
            negativePoint = i;
        treats[i] = (i == 0) ? temp : treats[i-1] + temp;
    }
    for (i = 0; i < q; i++)
    {
        output = 0;
        scanf("%lld%lld%lld", &l, &r, &m);
        long long int number = (r >= m) ? m-1 : r-1;
        if (negativePoint != -1) {
            if (l-1 >= negativePoint) {
                output = 0;
            } else if (l-1+number >= negativePoint) {
                number = negativePoint-l;
                output = (l-2 >= 0) ? treats[l-1+number] - treats[l-2] : treats[l-1+number];
            } else {
                output = (l-2 >= 0) ? treats[l-1+number] - treats[l-2] : treats[l-1+number];
            }
        } else {
            output = (l-2 >= 0) ? treats[l-1+number] - treats[l-2] : treats[l-1+number];
        }
        printf("%lld\n", output);
    }
    
    return 0;
}