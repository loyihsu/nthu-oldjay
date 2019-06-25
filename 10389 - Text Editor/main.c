// Problem: http://140.114.86.238/problem/10389/
#include <stdio.h>
#define MAX_SIZE 500

char content[MAX_SIZE];
char input[MAX_SIZE];

int main()
{
    fgets(input, MAX_SIZE, stdin);
    int i = 0, j;
    int k = 0;  //index
    
    while (input[i] != 0 && input[i] != 10)
    {
        if (input[i] == '/')
        {
            if (input[i+1] == 'b')
            {
                i = i+10;
                if (k-1>=0)
                {
                    for (j = k; j<MAX_SIZE; j++) content[j-1] = content[j]; //putting the content backspace
                    k--; //go back
                }
            } else if (input[i+1] == 'n')
            {
                i = i+8;
                for (j = MAX_SIZE-1; j>k; j--) content[j] = content[j-1]; //putting the fronts backward to avoid overlapping
                content[k] = '\n';
                k++;
            } else if (input[i+1] == 'l')
            {
                i = i+5;
                if (k-1>=0) k--;
            } else if (input[i+1] == 'r')
            {
                i = i+6;
                if (content[k]!=0) k++;
            }
        } else {
            for (j = MAX_SIZE-1; j>k; j--) content[j] = content[j-1]; //putting the fronts backward to avoid overlapping
            content[k] = input[i];
            i++, k++;
            
        }
    }
    printf("%s", content);
    
    return 0;
}
