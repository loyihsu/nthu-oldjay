// Problem: http://140.114.86.238/problem/10887/
#include "function.h"
#include <stdlib.h>

int compare(const void *a, const void *b)
{
    const int ia = (*(Grade*)a).total;
    const int ib = (*(Grade*)b).total;
    const int c = (*(Grade*)a).Chinese;
    const int d = (*(Grade*)b).Chinese;
    const int e = (*(Grade*)a).English;
    const int f = (*(Grade*)b).English;
    const int g = (*(Grade*)a).math;
    const int h = (*(Grade*)b).math;
    const int i = (*(Grade*)a).science;
    const int j = (*(Grade*)b).science;
    const int k = (*(Grade*)a).ID;
    const int l = (*(Grade*)b).ID;
    
    if (ia == ib)
    {
        if (c==d)
        {
            if (g==h)
            {
                if (i == j)
                {
                    return k-l;
                }
                return j-i;
            }
            return f-e;
        }
        return d-c;
    }
    return ib-ia;
}
