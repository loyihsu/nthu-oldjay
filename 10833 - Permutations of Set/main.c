#include <stdio.h>
#include "function.h"

int main(void) {
    int num, i;

    scanf("%d",&num);
    for(i=0; i<num; i++)
        list[i]='1'+i;
    Perm(0,num);
    
    return 0;
}
