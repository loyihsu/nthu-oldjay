// Problem: http://140.114.86.238/problem/12038/
#include <stdio.h>

int main(void) {
    
    int i, j, pos = 0;
    char letter;
    char allLetters[26] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};
    
    scanf("%c", &letter);
    for (i = 0; i < 26; i++)
    {
        if (allLetters[i] == letter)
            pos = i;
    }
    for (i = 0; i <= pos; i++)
    {
        for (j = pos-i;  j > 0; j--)
            printf(" ");
        for (j = 0; j <= i; j++)
            printf("%c",  allLetters[j]);
        for (j = i-1; j >=0; j--)
            printf("%c", allLetters[j]);
        for (j = pos-i;  j > 0; j--)
            printf(" ");
        printf("\n");
    }
    
    return 0;
}