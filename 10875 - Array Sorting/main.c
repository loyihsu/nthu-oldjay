#include <stdio.h>
#include <stdlib.h>
#include "function.h"
int main(void)
{
    int i,j,n,N,R;
    scanf("%d", &N);
    int (*array)[COLUMN]; // array is a pointer to an one-dimensional array of COLUMN elements
    for(n=0;n<N;n++){
        scanf("%d", &R);
        array = (int(*)[COLUMN])malloc(sizeof(int)*COLUMN*R);
        for(i = 0; i < R; i++)
            for(j = 0; j < COLUMN; j++)
                scanf("%d", &array[i][j]);
        sortArray(R, array);
        for(i = 0; i < R; i++){
            printf("%d", array[i][0]);
            for(j = 1; j < COLUMN; j++){
                printf(" %d", array[i][j]);
            }
            printf("\n");
        }
        if(n!=N-1) printf("\n");
        free(array);
    }
    return 0;
}
