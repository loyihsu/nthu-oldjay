// Problem: http://140.114.86.238/problem/10237/
#include <stdio.h>
#include <stdlib.h>

int W;
void divide (int week, int first, int second, int third);

int main(void)
{
    scanf("%d", &W);
    divide(1,1,0,0);
    
    return 0;
}

void divide (int week, int first, int second, int third)
{
    if (week == W)
    {
        printf("%d\n", first+second+third);
    } else
    {
        divide(week+1, first+second, first, second);
    }
    return;
}
