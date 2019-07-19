// Problem: http://140.114.86.238/problem/10897/
#include <stdio.h>

char map[501][501];
int count;

void path(int R, int C, int pr, int pc, int steps);

int main(void) {
    int number, x, y, sx = 0, sy = 0, i, j, k;
    
    scanf("%d", &number);
    
    for (i = 0; i < number; i++) {
        count = 250000;
        
        scanf("%d %d\n", &x, &y);
        
        for (j = 0; j < x; j++)
            for (k = 0; k <= y; k++)
                scanf("%c", &map[j][k]);
        
        for (j = 0; j < x; j++) {
            for (k = 0; k <= y; k++) {
                if (map[j][k] == 'S') {
                    sx = j;
                    sy = k;
                }
            }
        }
        
        path(x, y, sx, sy, 0);
        
        if (count != 250000) printf("%d\n", count);
        else printf("-1\n");
    }
    
    return 0;
}

void path(int R, int C, int pr, int pc, int step) {
    if (map[pr][pc] == 'F') {
        //find the minimum
        if (step < count) count = step;
        return;
    }
    
    map[pr][pc] = '#';  //to avoid going backward
    
    if (pr - 1 >= 0 && map[pr-1][pc] != '#') path(R, C, pr-1, pc, step+1);  //leftmove
    if (pr + 1 < R && map[pr+1][pc] != '#') path(R, C, pr+1, pc, step+1);   //rightmove
    if (pc - 1 >= 0 && map[pr][pc-1] != '#') path(R, C, pr, pc-1, step+1);  //upmove
    if (pc + 1 < C && map[pr][pc+1] != '#') path(R, C, pr, pc+1, step+1);   //downmove
    
    map[pr][pc] = '$';  //to avoid influence on others
}
