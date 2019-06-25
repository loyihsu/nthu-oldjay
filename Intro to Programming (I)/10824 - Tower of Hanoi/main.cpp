#include <stdio.h>
#include "function.h"

int main(){
    int n;
    scanf("%d", &n);
    hanoi(n, 'A', 'B', 'C');
    return 0;
}
