// Problem: http://140.114.86.238/problem/10881/
#include <stdio.h>
#include "function.h"

void area(Rect *r1, Rect *r2) {
    int i, j, k, l, count = 0;
    
    for (i = r1->x; i<r1->x+r1->width; i++)
        for (j = r1->y; j<r1->y+r1->length; j++)
            for (k = r2->x; k<r2->x+r2->width; k++)
                for (l = r2->y; l<r2->y+r2->length; l++)
                    if (i == k && j == l) count++;
    
    r1->leftArea = r1->width * r1->length - count;
    r2->leftArea = r2->width * r2->length - count;
}
