// Problem: http://140.114.86.238/problem/10850/
#include <stdio.h>
#include <stdlib.h>

void swap(char *a, char *b) {
    char temp = *b;
    *b = *a;
    *a = temp;
}

int main(void) {
    char str[5];
    int lines, i, j, HIT[10000] = { 0 };
    
    scanf("%d", &lines);
    while (lines--) {
        scanf("%s", str);
        for (i = 4; i > 0; i--)
            for (j = 1; j < i; j++)
                if (str[j-1] > str[j])
                    swap(&str[j-1], &str[j]);
        HIT[atoi(str)]++;
    }

    for (i = 0; i<10000; i++)
        if (HIT[i] >= 2)
            printf("%d\n", i);
    
    return 0;
}
