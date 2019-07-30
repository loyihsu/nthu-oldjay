// Problem: http://140.114.86.238/problem/10954/
#include <stdio.h>

char expr[200];
int pos;

int exec(int a, int b, int c, int d){
    char chat;
    int op1, op2;
    
    chat = expr[pos++];
    
    if (chat == '&') {
        op1 = exec(a, b, c, d);
        op2 = exec(a, b, c, d);
        return op1 && op2;
    } else if (chat == '|') {
        op1 = exec(a, b, c, d);
        op2 = exec(a, b, c, d);
        return op1 || op2;
    } else if (chat == 'A') {
        return a;
    } else if (chat == 'B') {
        return b;
    } else if (chat == 'C') {
        return c;
    } else if (chat == 'D') {
        return d;
    }

    return -1;
}

int main(void) {
    int i, j, k, l, output;

    scanf("%s", expr);

    for (i = 0; i<2; i++) {
        for (j = 0; j<2; j++) {
            for (k = 0; k<2; k++) {
                for (l = 0; l<2; l++) {
                    pos = 0;
                    output = exec(i, j, k, l);
                    printf("%d %d %d %d %d\n", i, j, k, l, output);
                }
            }
        }
    }
    
    return 0;
}

