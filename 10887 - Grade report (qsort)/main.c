#include <stdio.h>
#include <stdlib.h>
#include "function.h"

int main(){
    int n, i;
    Grade gradeList[1000];
    scanf("%d", &n);

    for(i = 0; i < n; i++)
    {
        scanf(
            "%d %d %d %d %d",
            &gradeList[i].ID,
            &gradeList[i].Chinese,
            &gradeList[i].English,
            &gradeList[i].math,
            &gradeList[i].science
        );

        gradeList[i].total =
            gradeList[i].Chinese
            + gradeList[i].English
            + gradeList[i].math
            + gradeList[i].science;
    }

    qsort(gradeList, n, sizeof(Grade), compare);

    for(i = 0; i < n; i++) {
        printf(
            "%d\t%d\t%d\t%d\t%d\t%d\n",
            gradeList[i].ID,
            gradeList[i].total,
            gradeList[i].Chinese,
            gradeList[i].English,
            gradeList[i].math,
            gradeList[i].science
        );
    }
    return 0;
}
