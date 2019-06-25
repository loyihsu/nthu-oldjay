#include <stdio.h>
#include "function.h"
int main(void){
    Rect r1,r2;
    scanf("%d%d%d%d",&r1.x,&r1.y,&r1.width,&r1.length);
    scanf("%d%d%d%d",&r2.x,&r2.y,&r2.width,&r2.length);

    area(&r1,&r2);

    printf("%d %d",r1.leftArea,r2.leftArea);

    return 0;
}