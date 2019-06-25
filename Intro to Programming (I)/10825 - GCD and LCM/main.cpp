#include <stdio.h>
#include "function.h"

int main(void)
{
    int x,y;
    scanf("%d %d",&x,&y);
    printf("%d %d",gcd(x,y),lcm(x,y));

    return 0;
}
