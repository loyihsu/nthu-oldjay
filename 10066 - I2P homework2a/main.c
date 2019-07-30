// Problem: http://140.114.86.238/problem/10066/
#include <stdio.h>

float convertToFloat(char n) {
    return (float) n - '0';
}

int main(void) {
    char digits[3];
    float num=0, rev=0;
    
    scanf("%s", digits);
    num = convertToFloat(digits[0]) * 100 + convertToFloat(digits[1]) * 10 + convertToFloat(digits[2]); // In-order
    rev = convertToFloat(digits[2]) * 100 + convertToFloat(digits[1]) * 10 + convertToFloat(digits[0]); // Reverse order
    printf("%.1f", (num+rev)/2);
    
    return 0;
}

