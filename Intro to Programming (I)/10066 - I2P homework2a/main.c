// Problem: http://140.114.86.238/problem/10066/
#include <stdio.h>

int main(void) {
    char digits[3];
    float num=0, rev=0;
    
    scanf("%s", digits);
    num = (float)digits;
    rev = (float){digits[2], digits[1], digits[0]};
    
	return 0;
}
