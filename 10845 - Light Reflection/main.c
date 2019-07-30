// Problem: http://140.114.86.238/problem/10845/
#include <stdio.h>

int main(void) { 
    int i, j, k, direction, width, height, count = 0;
    int upperRight = 0, lowerRight = 1, upperLeft = 2, lowerLeft = 3;
    
    scanf("%d%d", &width, &height);
    scanf("%d%d", &i, &j);
    scanf("%d", &k);
    direction = upperRight;
    while (count < k-1) {
        if (((i == 1)||(i == width))&&((j == 1)||(j == height)))
            break;
        
        if (direction == upperRight) {
            while (i > 1 && j < height) {
                i--; j++;
            }
            direction = (i == 1) /* left wall */ ? lowerRight : (j == height) /* buttom */ ? upperLeft : direction;
        } else if (direction == lowerRight) {
            while (i < width && j < height) {
                i++; j++;
            }
            direction = (i == width) /* right wall */ ? upperRight : (j == height) /* buttom */ ? lowerLeft : direction;
        } else if (direction == upperLeft) {
            while (i > 1 && j > 1) {
                i--; j--;
            }
            direction = (i == 1) /* left wall */ ? lowerLeft : (j == 1) /* Top*/ ? upperRight : direction;
        } else if (direction == lowerLeft) {
            while (i < width && j > 1) {
                i++; j--;
            }
            direction = (i == width) /* right wall */ ? upperLeft : (j == 1) /* Top*/ ? lowerRight : direction;
        }
        count++;
    }
    printf("(%d,%d)", i, j);
    
    return 0;
}