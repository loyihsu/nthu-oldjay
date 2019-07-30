// Problem: http://140.114.86.238/problem/10848/
#include <stdio.h>
#include "function.h"

void flooding(int R, int C, int pr, int pc) {
    if (Map[pr][pc] == 'H') {
        Map[pr][pc] = 'W';
        if (pr+1 < R)                   // Right
            flooding(R, C, pr+1, pc);
        if (pr - 1 >= 0)                // Left
            flooding(R, C, pr-1, pc);
        if (pc + 1 < C)                 // Down
            flooding(R, C, pr, pc+1);
        if (pc - 1 >= 0)                // Up
            flooding(R, C, pr, pc-1);
    }
}