// Problem: http://140.114.86.238/problem/10846/
#include <stdio.h>
#include "function.h"

void findNPC(int num) {
    int i;

    printf("%d\n", num);
    for (i = 0; ; i++) if (NPClist[num][i] == 0) break;
    else findNPC(NPClist[num][i]);
}
