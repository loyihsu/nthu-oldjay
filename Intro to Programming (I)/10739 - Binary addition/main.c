// Problem: http://140.114.86.238/problem/10739/
#include <stdio.h>

int tm(int, int);

int main(void)
{
    int i, j, carries;
    int num[11] = {0};
    int rnum[12] = {0};
    scanf("%d", &rnum[11]);
    int add = 1;
    int r, q;
    
    
    i = 10;
    
    while (i>=0)
    {
        num[i] = rnum[i+1]/(tm(2, i));
        rnum[i] = rnum[i+1]%(tm(2, i));
        i--;
    }
    
    carries = 0;
    
    j = 0;
    while (add==1)
    {
        r = (num[j]+add)%2;
        q = (num[j]+add)/2;
        if (num[j]+add==2)
        {
            carries++;
        }
        num[j] = r;
        add = q;
        j++;
    }
    
    i = 10;
    
    while (num[i]==0) i--;
    while (i>=0) printf("%d", num[i--]);
    
    printf(" %d", carries);
    
}

int tm(int number, int times)
{   int n = 1;
    int i;
    for (i=0; i<times; i++)
    {
        n = n*number;
    }
    
    return n;
}
