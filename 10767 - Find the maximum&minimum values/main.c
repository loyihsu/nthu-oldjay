// Problem: http://140.114.86.238/problem/10767
#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int gridX, gridY, maxvalue=0, minvalue=0, maxI=-1, maxJ=-1, minI=-1, minJ=-1, i, j, temp;
    
    scanf("%d%d", &gridX, &gridY);
    
    for (i = 0; i < gridX; i++) {
        for (j = 0; j < gridY; j++) {
            scanf("%d", &temp);
            if ((maxI == -1 && maxJ == -1) || temp > maxvalue) {
                maxvalue = temp;
                maxI = i;
                maxJ = j;
            }
            if ((minI == -1 && minJ == -1) || temp < minvalue) {
                minvalue = temp;
                minI = i;
                minJ = j;
            }
        }
    }
    
    printf("%d %d", abs(maxI-minI) + abs(maxJ-minJ) , abs(maxvalue-minvalue));
    
    return 0;
}
