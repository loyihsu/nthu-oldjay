#include <stdio.h>
#include <string.h>
#include "function.h"

int main() {
    char str[5000];

    while (EOF != scanf("%s", str)) {
        char *start = str, *end = start + strlen(str) - 1;
        if (isPalindrome(start, end))
            printf("Yes\n");
        else
            printf("No\n");
    }
    
    return 0;
}
