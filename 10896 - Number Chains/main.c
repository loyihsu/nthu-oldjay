// Problem: http://140.114.86.238/problem/10896/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char number[11];
int result[1005];

int asc(const void *a, const void *b) {
    const char *ia = (const char *) a;
    const char *ib = (const char *) b;
    return *ia-*ib;
}

int desc(const void *a, const void *b) {
    const char *ia = (const char *) a;
    const char *ib = (const char *) b;
    return *ib-*ia;
}

int sorting (char order[]) {
    if (!strcmp(order, "asc"))
        qsort(number,strlen(number),sizeof(char),asc);
    else
        qsort(number,strlen(number),sizeof(char),desc);
    
    int integer = atoi(number);
    
    return integer;
}

int sameResult(int newNum, int NumOfChains) {
    int i, same = 0;
    for (i = 0; i< NumOfChains; i++) {
        if (newNum == result[i]) {
            same = 1;
            break;
        }
    }
    return same;
}

int main(void) {
    int chains = 0, tmp = 0;
    
    scanf("%s", number);
    
    while (strcmp(number,"0")) {
        while (1) {
            tmp = (sorting("desc") - sorting("asc"));
            if (!sameResult(tmp,chains)) {
                result[chains] = tmp;
                chains++;
                sprintf(number, "%d", tmp);
            } else {
                chains++;
                printf("%d\n", chains);
                chains = 0;
                break;
            }
        }
        scanf("%s", number);
    }
    
    return 0;
}
