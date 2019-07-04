// Problem: http://140.114.86.238/problem/10739/
#include <stdio.h>

int power(int number, int pow) {
    int output = 1, i;
    
    for (i = 0; i < pow; i++)
        output *= number;
        
    return output;
}

int main(void) {
    int num = 0, binaryNum[12] = { 0 }, i, carries = 0, pos = 0;
    
    scanf("%d", &num);
    for (i = 0; i < 12; i++) {
        binaryNum[i] = num / power(2, 11-i);
        num -= binaryNum[i] * power(2, 11-i);
    }
    binaryNum[11] += 1;
    for (i = 11; i >= 0; i--) {
        if (binaryNum[i] > 1) {
            binaryNum[i]   -= 2;
            binaryNum[i-1] += 1;
            carries += 1;
        }
    }
    for (i = 0; i < 12; i++) {
        if (!pos) {
            if (i+1 < 12)
                if (binaryNum[i+1])
                    pos = 1;
        } else {
            printf("%d", binaryNum[i]);
        }
    }
    printf(" %d", carries);
    
    return 0;
}