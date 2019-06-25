#ifndef FUNCTION_H
#define FUNCTION_H
typedef struct
{
   int ID;
   int Chinese, English, math, science;
   int total;
} Grade;
int compare(const void *a, const void *b);
#endif
