// Problem: http://140.114.86.238/problem/10768/
#include <stdio.h>

int main(void)
{
    int a, b;
    char c;
    int i, j, k;
    
    scanf("%c%d%d", &c, &a, &b);
    if (a != 1)
    {
        //print times
        for (k = 0; k<b; k++)
        {
            //print upper
            for (i = 0; i<=a; i++)
            {
                for (j = 1; j<=i; j++)
                {
                    printf("%c", c);
                    
                    if (j == i)
                    {
                        printf("\n");
                    }
                }
                
            }
            
            //print lower
            for (i = a-1; i>1; i--)
            {
                for (j = 1; j<=i; j++)
                {
                    printf("%c", c);
                    
                    if (j == i)
                    {
                        printf("\n");
                    }
                }
                
            }
        }
        printf("%c", c);
    } else {
        //print times
        for (k = 0; k<b-1; k++)
        {
            printf("%c\n", c);
        }
        printf("%c", c);
    }
    
    return 0;
}
