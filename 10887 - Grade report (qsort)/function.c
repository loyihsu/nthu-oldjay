// Problem: http://140.114.86.238/problem/10887/
#include "function.h"
#include <stdlib.h>

int compare (const void * a, const void * b) {
    const Grade* ca = (Grade*) a;
    const Grade* cb = (Grade*) b;
    
    if (!((*ca).total == (*cb).total)) return (*cb).total - (*ca).total;
    else if (!((*ca).Chinese == (*cb).Chinese)) return (*cb).Chinese - (*ca).Chinese;
    else if (!((*ca).English == (*cb).English)) return (*cb).English - (*ca).English;
    else if (!((*ca).math == (*cb).math)) return (*cb).math - (*ca).math;
    else if (!((*ca).science == (*cb).science)) return (*cb).science - (*ca).science;
    else return (*ca).ID - (*cb).ID;
}