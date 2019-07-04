// Problem: http://140.114.86.238/problem/10774/
#include <stdio.h>

int main(void) {
    int array[4], num = 4, mode = -1, common = 0;
    
    while (num--)
        scanf("%d", &array[3-num]);
    
    mode = ((array[1]-array[0]) == (array[3] - array[2])) ? 0 : 1;
    if (mode == 0) {                                // arithmetic
        common = array[3] - array[2];
        printf("%d %d", array[3]+common, common);
    } else {                                        // geometric
        common = array[3] / array[2];
        printf("%d %d", array[3]*common, common);
    }
    
    return 0;
}