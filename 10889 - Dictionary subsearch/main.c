// Problem: http://140.114.86.238/problem/10889/
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(void)
{
    char words[1000][101];
    char lower[1000][101];
    char find[11], lowerf[11];
    char *answer[1000];
    int num;
    int i, j;
    
    //get input
    scanf("%d", &num);
    
    for (i = 0; i<num; i++)
    {
        scanf("%s", words[i]);
        
        for (j = 0; j<101; j++)
        {
            //to lower
            lower[i][j] = tolower(words[i][j]);
        }
    }
    
    scanf("%s", find);
    
    for (i = 0; i<11; i++) lowerf[i] = tolower(find[i]);
    
    for (j = 0; j<101; j++)
    {
        //to lower
        lower[i][j] = tolower(words[i][j]);
    }
    
    //process
    for (i = 0; i<num; i++)
    {
        answer[i] = strstr(lower[i], lowerf);
    }
    
    //print
    for (i = 0; i<num; i++)
    {
        if (answer[i] != NULL)
        {
            printf("%s\n", words[i]);
        }
    }
    
    return 0;
}
