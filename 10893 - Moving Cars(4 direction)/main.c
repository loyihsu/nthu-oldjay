#include <stdio.h>
#include "function.h"
int main(void)
{
    int i,j,k;
    int num_cars;

    scanf("%d",&num_cars);
    //reset map
    for (i=0; i<MAP_SIZE; i++) {
        for (j=0; j<MAP_SIZE; j++) {
            map[i][j] = SPACE;
        }
    }
    //read coordinates of cars and put them on the map
    for (i=0; i<num_cars; i++) {
        scanf("%d%d%d%d", &cars[i][0], &cars[i][1], &cars[i][2], &cars[i][3]);
        for (j=cars[i][0]; j<=cars[i][2]; j++) {
            for (k=cars[i][1]; k<=cars[i][3]; k++) {
                map[j][k] = i+'0';
            }
        }
    }
    list_moves(num_cars);
    return 0;
}


