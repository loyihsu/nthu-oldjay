// Problem: http://140.114.86.238/problem/10889/
#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main(void) {
    int n, i;
    char string[1001][101], tmp[1001][101], find[11];
    
    scanf("%d", &n);
    for (i = 0; i<n; i++)
        scanf("%s", string[i]);
    
    scanf("%s", find);
    
    for (i = 0; i<n; i++)
        for (int j = 0; j < 101; j++)
            tmp[i][j] = tolower(string[i][j]);

    for (i = 0; i < 11; i++)
        find[i] = tolower(find[i]);
    
    for (i = 0; i<n; i++)
        if (strstr(tmp[i],find))
            printf("%s\n", string[i]);
    
    return 0;
}
