#include <stdio.h>
#include <stdlib.h>

#include "function.h"

#define MAX_FLOOR_NUM 20000
#define RED 0
#define BLUE 1

int design(int floorNum, Floor floorArr[]) {
    int height, color;
    int idx;

    qsort(floorArr, floorNum, sizeof(Floor), compare);

    height = 0;
    color = (floorArr[0].color == 'B') ? BLUE : RED;

    for (idx = 0; idx < floorNum; idx++) {
        if (color == BLUE && floorArr[idx].color == 'B') {
            height++;
            color = RED;
        }
        else if (color == RED && floorArr[idx].color == 'R') {
            height++;
            color = BLUE;
        }
    }
    return height;
}

int main() {
    int floorNum;
    int i;

    Floor floorArr[MAX_FLOOR_NUM];

    scanf("%d", &floorNum);

    for (i = 0; i < floorNum; i++) {
        scanf(" %c %d", &floorArr[i].color, &floorArr[i].size);
    }

    printf("%d", design(floorNum, floorArr));

    return 0;
}

