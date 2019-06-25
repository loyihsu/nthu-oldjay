#include <stdio.h>
#include <string.h>

int main(void)
{
    
    char stringa[4] = {0};
    char stuff[10][9] = {0};
    int n, i, j, k, big = 0, max[10] = {0};
    unsigned long length;
    i = 0;
    
    scanf("%s", stringa);
    scanf("%d", &n);
    
    for (i = 0; i < n; i++)
    {
        scanf("%s", stuff[i]);
    }
    length = strlen(stringa);
    
    
    i = 0;
    {
        for (j = 0; j<9; j++)
        {
            if (length == 2){
                for (k = 0; k < 8; k++)
                {
                    if (stringa[i] == stuff[j][k] && stringa[i+1] == stuff[j][k+1])
                    {
                        max[j]++;
                    }
                }
            } else if (length == 3)
            {
                for (k = 0; k < 8; k++)
                {
                    if (stringa[i] == stuff[j][k] && stringa[i+1] == stuff[j][k+1] && stringa[i+2] == stuff[j][k+2])
                    {
                        max[j]++;
                    }
                }
            } else if (length == 4)
            {
                for (k = 0; k < 7; k++)
                {
                    if (stringa[i] == stuff[j][k] && stringa[i+1] == stuff[j][k+1] && stringa[i+2] == stuff[j][k+2] && stringa[i+3] == stuff[j][k+3])
                    {
                        max[j]++;
                    }
                }
            } else if (length == 1)
            {
                for (k = 0; k < 9; k++)
                {
                    if (stringa[i] == stuff[j][k])
                    {
                        max[j]++;
                    }
                }
            }
        }
    }
    
    for (i = 0; i<9; i++)
    {
        big = (max[i]>=big)?max[i]:big;
    }
    
    printf("%d", big);
    
    return 0;
}
