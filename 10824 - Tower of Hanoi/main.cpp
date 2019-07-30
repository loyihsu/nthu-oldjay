#include <stdio.h>
#include "function.h"

int main(void){
    int n;
    scanf("%d", &n);
    hanoi(n, 'A', 'B', 'C');
    return 0;
}
