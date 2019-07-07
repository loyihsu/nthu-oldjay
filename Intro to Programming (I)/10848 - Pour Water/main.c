#include <stdio.h>
#include "function.h"

int main(void) {
    int N, R, C, X, i, j, k;

    scanf("%d", &N);
    for(k=0;k<N;k++) {
        scanf("%d%d%d", &R, &C, &X);
        for(i=0;i<R;i++)
            for(j=0;j<C;j++)
                Map[i][j] = ' ';
            
        for(i=0;i<R;i++)
            scanf("%s", Map[i]);

        flooding(R,C,0,X);
        
        for(i=0;i<R;i++) {
            for(j=0;j<C;j++)
                printf("%c", Map[i][j]);
            printf("\n");
        }
        if(k<N-1)
            printf("\n");
    }
    
    return 0;
}
