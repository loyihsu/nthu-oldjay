#include <stdio.h>
#include "function.h"

void flooding(int R, int C, int pr, int pc)
{
    if (Map[pr][pc] == 'H')
    {
        Map[pr][pc] = 'W';
    }
    
    if (Map[pr][pc] == 'W')
    {
        if (pr-1 >= 0)
        {
            if (Map[pr-1][pc] == 'H')
            {
                flooding(R, C, pr-1, pc);
            }
        }
        
        if (pr+1 < R)
        {
            if (Map[pr+1][pc] == 'H')
            {
                flooding(R, C, pr+1, pc);
            }
        }
        
        if (pc-1 >= 0)
        {
            if (Map[pr][pc-1] == 'H')
            {
                flooding(R, C, pr, pc-1);
            }
        }
        if (pc+1 < C)
        {
            if (Map[pr][pc+1] == 'H')
            {
                flooding(R, C, pr, pc+1);
            }
        }
    }
}
