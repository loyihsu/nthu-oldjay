// Problem: http://140.114.86.238/problem/10898/
#include <stdio.h>

int main(void) {
    int mapsize, i, j, array[51][51], bomb, p_x, p_y, flag;
    
    scanf("%d", &mapsize);
    
    for (i = 0; i < mapsize; i++)
        for (j = 0; j < mapsize; j++)
            scanf("%d", &array[i][j]);
    
    scanf("%d", &bomb);
    
    for (i = 0; i < bomb; i++) {
        scanf("%d%d", &p_x, &p_y);
        array[p_x-1][p_y-1] = 0;
    }
    
    for (i = 0; i < mapsize; i++) {
        flag = 0;
        for (j = 0; j < mapsize; j++){
            if (i != j)
                if (array[i][j]) {
                    flag = 1;
                    break;
                }
        }
        for (j = 0; j < mapsize; j++){
            if (i != j)
                if (array[j][i]) {
                    flag = 1;
                    break;
                }
        }
        if (!flag) printf("%d\n", i+1);
    }
    
    return 0;
}
