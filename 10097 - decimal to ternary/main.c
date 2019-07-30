// Problem: http://140.114.86.238/problem/10097/
#include <stdio.h>

int pow(int base, int power) {
    int output = 1, i;
    for (i = 0; i < power; i++) {
        output *= base;
    }
    return output;
}

int main(void) {
    int x, y, i;
    
    scanf("%d%d", &x, &y);
    
    char output[y];
    
    for (i = 0; i < y; i++) {
        int place = x/pow(3, y-i-1); // Convert to ternary
        output[i] = place + '0';     // To char
        x -= place * pow(3, y-i-1);  // Keep the number (x) at the amount after conversion
    }
    printf("%s\n", output);
    
    return 0;
}
