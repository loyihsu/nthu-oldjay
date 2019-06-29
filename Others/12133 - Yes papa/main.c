// Problem: http://140.114.86.238/problem/12133/
#define STRLENGTH 100000
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int checkEquation(char* strA, char* strB) {
    if (!strcmp(strA, strB)) {
        return 1;
    } else {
        unsigned long len = strlen(strA);
        if (len % 2 == 1) {
            return 0;
        } else {
            unsigned long sublength = len/2;
            char *sub[4];
            int i;
            
            for (i = 0; i < 4; i++)
                sub[i] = (char*)malloc(sublength*sizeof(char));
            
            
            strncpy(sub[0], strA, sublength);
            strncpy(sub[1], strA+sublength, sublength);
            strncpy(sub[2], strB, sublength);
            strncpy(sub[3], strB+sublength, sublength);
            
            if ((checkEquation(sub[0], sub[2]) && checkEquation(sub[1], sub[3])) || ((checkEquation(sub[0], sub[3]) && checkEquation(sub[1], sub[2])))) {
                return 1;
            }
        }
    }
    
    return 0;
}

int main(void) {
    char stringA[STRLENGTH], stringB[STRLENGTH];
    scanf("%s", stringA);
    scanf("%s", stringB);
    
    if (checkEquation(stringA, stringB) == 1) {
        printf("%s\n", "YES");
    } else {
        printf("%s\n", "NO");
    }
    
    return 0;
}


