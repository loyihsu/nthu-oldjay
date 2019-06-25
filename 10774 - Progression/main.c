// Problem: http://140.114.86.238/problem/10774/
#include <stdio.h>

int main(void)
{
    
    
    int inputnum[4];
    int i;
    int next, common;
    int commonma, commonmb;
    int commonra, commonrb;
    
    for (i = 0; i < 4; i++)
    {
        scanf("%d", &inputnum[i]);
    }
    
    commonma = inputnum[1]-inputnum[0];
    commonmb = inputnum[2]-inputnum[1];
    
    commonra = inputnum[1]/inputnum[0];
    commonrb = inputnum[2]/inputnum[1];
    
    
    if (commonma == commonmb)
    {
        common = inputnum[1]-inputnum[0];
        next = inputnum[3] + common;
    } else if (commonrb == commonra) {
        common = inputnum[1]/inputnum[0];
        next = inputnum[3] * common;
    }
    
    printf("%d %d", next, common);
    
    
    return 0;
}
