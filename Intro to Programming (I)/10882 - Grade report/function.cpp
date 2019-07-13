// Problem: http://140.114.86.238/problem/10882/
#include <stdio.h>
#include <stdlib.h>
#include "function.h"

int cmp (const void * a, const void * b) {
    const Grade* ca = (Grade*) a;
    const Grade* cb = (Grade*) b;
    
    if (!((*ca).total == (*cb).total)) return (*cb).total - (*ca).total;
    else if (!((*ca).Chinese == (*cb).Chinese)) return (*cb).Chinese - (*ca).Chinese;
    else if (!((*ca).English == (*cb).English)) return (*cb).English - (*ca).English;
    else if (!((*ca).math == (*cb).math)) return (*cb).math - (*ca).math;
    else if (!((*ca).science == (*cb).science)) return (*cb).science - (*ca).science;
    else return (*ca).ID - (*cb).ID;
}

void sortGrade(Grade *gList, int n) {
    int i;
    
    for (i = 0; i<n; i++)
        gList[i].total = gList[i].Chinese + gList[i].English + gList[i].math + gList[i].science;
    
    qsort(gList, n, sizeof(Grade), cmp);
}