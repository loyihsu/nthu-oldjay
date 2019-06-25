// Problem: http://140.114.86.238/problem/10850/
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    char str[5];
    int HIT[10000] = {0};
    int temp;
    int i, j, k, l;
    
    scanf("%d", &i);
    for (j = 0; j < i; j++)
    {
        scanf("%s", str);
        for (k = 4; k > 0; k--)
        {
            for (l = 1; l < k; l++)
            {
                if(str[l-1]>str[l])
                {
                    temp = str[l];
                    str[l] = str[l-1];
                    str[l-1] = temp;
                }
            }
        }
        HIT[atoi(str)]++;
    }
    
    for (i = 0; i<10000; i++)
    {
        if (HIT[i]>=2)
        {
            printf("%d\n", i);
        }
    }
    
    return 0;
}
