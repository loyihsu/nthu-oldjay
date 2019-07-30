// Problem: http://140.114.86.238/problem/10772
#include <stdio.h>
#include <string.h>

int main(void) {
    char str[4] = "", cur[9] = "";
    int n, i, j, max = 0, count = 0, flag = 0;
    
    scanf("%s", str);
    scanf("%d", &n);
    
    unsigned long findLen = strlen(str), findeeLen = 0;
    
    while (n--) {
        count = 0;
        scanf("%s", cur);
        findeeLen = strlen(cur);
        for (i = 0; i < findeeLen; i++) {
            if (cur[i] == str[0]) {
                flag = 1; // Raise the flag when check that the current character equals to `str`
                for (j = 0; j < findLen; j++) {
                    // Check the rest of the string
                    if (cur[i+j] != str[j])
                    {
                        flag = 0; // Put down the flag if found different char within the length of `str`
                        break;    // Break the loop as it won't be the same
                    }
                }
                if (flag == 1)
                    count += 1; // Count it if the flag was not put down all the way
            }
        }
        if (count >= max)
            max = count;    // Save the maximum if the current `count` is bigger than the max
    }
    printf("%d", max);
    
    return 0;
}