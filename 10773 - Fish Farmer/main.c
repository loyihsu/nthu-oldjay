// Problem: http://140.114.86.238/problem/10773/
#include <stdio.h>

int main(void)
{
    int N = 0, M = 0;
    int k = 0; //years
    int i = 0;
    char pond;
    int num;
    
    scanf("%d %d", &N, &M);
    scanf("%d", &k);
    
    for (i = 0; i<k; i++)
    {
        scanf("%c %d", &pond, &num);
        while (pond=='\n') scanf("%c %d", &pond, &num);
        N = (1.08)*N;
        M = (1.08)*M;
        if (pond == 'A')
        {
            N = N-num;
            M = M+num;
        } else if (pond == 'B')
        {
            M = M-num;
            N = N+num;
        }
    }
    
    printf("%d %d\n", N, M);
    return 0;
}
