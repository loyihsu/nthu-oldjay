// Problem: http://140.114.86.238/problem/10741/

#include <stdio.h>

int main(void) {
    int input[3];

    scanf("%1d%1d%1d", &input[0], &input[1], &input[2]);
    input[0] = (input[0]%2 == 0) ? 'A' : 'B';
    input[1] = (input[1]%2 == 0) ? 'C' : 'D';
    input[2] = (input[2]%2 == 0) ? 'E' : 'F';
    printf("%c%c%c", input[0], input[1], input[2]);

    return 0;
}