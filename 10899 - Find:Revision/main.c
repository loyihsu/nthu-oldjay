#include <stdio.h>
#include <stdlib.h>
#include "function.h"

int main()
{
    int num, i;
    char instr;
    int isEnd=0;
    Info List[SIZE];

    scanf("%d", &num);
    for(i=0;i<num;i++){
        scanf("%s%s%s", List[i].Name, List[i].Height, List[i].Weight);
    }

    while(!isEnd){
        getchar();
        scanf("%c", &instr);
        Find_Revise(List, num, instr, &isEnd);
    }

    return 0;
}
