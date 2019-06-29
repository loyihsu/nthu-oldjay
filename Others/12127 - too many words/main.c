// Problem: http://140.114.86.238/problem/12127/
#include <stdio.h>

int main(int argc, const char * argv[]) {
    
    char temp[256] = "";
    while (!feof(stdin)) {
        gets(temp);
        printf("%s",temp);
        
        if (!feof(stdin))
        {
            printf("\n");
        }
    }
    
    return 0;
}