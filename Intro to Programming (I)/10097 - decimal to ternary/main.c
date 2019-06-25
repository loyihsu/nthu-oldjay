// Problem: http://140.114.86.238/problem/10097/
#include <stdio.h>

int power(int, int);

int main(void)
{
    int i, outnum;
    int j;
    int output[8] = {0}, routput[9] = {0};
    scanf("%d %d", &routput[8], &outnum);
    
    i = 7;
    while (i>=0)
    {
        output[i] = routput[i+1]/(power(3, i));
        routput[i] = routput[i+1]%(power(3, i));
        i--;
    }
    
    j = outnum - 1;
    while (j>=0) printf("%d", output[j--]);
    
    printf("\n");
    
    return 0;
}

int power(int number, int times)
{
    int i = 0, n = 1;
    while (i<times)
    {
        n = number * n;
        i++;
    }
    
    return n;
}
