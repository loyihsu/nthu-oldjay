// Problem: http://140.114.86.238/problem/10885/
#include <stdlib.h>
#include "function.h"

int compare(const void *a, const void *b) {
    return ((*(Floor*)a).size)-((*(Floor*)b).size);
}

