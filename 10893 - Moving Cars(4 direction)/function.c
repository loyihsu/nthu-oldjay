// Problem: http://140.114.86.238/problem/10893/
#include <stdio.h>
#include "function.h"

int max(int a, int b) {
    return (a>b)?a:b;
}

int min(int a, int b) {
    return (a<b)?a:b;
}

int checkvalid(int row, int col, int checkmin, int checkmax) {
    int i;
    if (row != -1){
        //row fixed
        for (i = checkmin; i<=checkmax; i++){
            if (map[row][i] != SPACE)
                return 0;
        }
    } else if (col != -1) {
        //col fixed
        for (i = checkmin; i<=checkmax; i++){
            if (map[i][col] != SPACE)
                return 0;
        }
    }
    return 1;
}

void list_moves(int num){
    int i, j;
    int array[4];
    
    for (i = 0; i<num; i++) {
        
        for (j = 0; j<4; j++) array[j] = 0;
        
        //right
        for (j = max(cars[i][1],cars[i][3])+1; j < MAP_SIZE; j++)
            if(checkvalid(-1, j, min(cars[i][0],cars[i][2]), max(cars[i][0],cars[i][2]))) array[0]++;
            else break;
        
        //down
        for (j = max(cars[i][0],cars[i][2])+1; j < MAP_SIZE; j++)
            if(checkvalid(j, -1, min(cars[i][1],cars[i][3]), max(cars[i][1],cars[i][3]))) array[1]++;
            else break;
        
        //left
        for (j = min(cars[i][1],cars[i][3])-1; j >= 0; j--)
            if(checkvalid(-1, j, min(cars[i][0],cars[i][2]), max(cars[i][0],cars[i][2]))) array[2]++;
            else break;
        //up
        for (j = min(cars[i][0],cars[i][2])-1; j >= 0; j--)
            if(checkvalid(j, -1, min(cars[i][1],cars[i][3]), max(cars[i][1],cars[i][3]))) array[3]++;
            else break;
        
        printf("%d %d %d %d\n", array[0], array[1], array[2], array[3]);
    }
}
