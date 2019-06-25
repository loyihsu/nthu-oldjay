#ifndef FUNCTION_H
#define FUNCTION_H
typedef struct
{
   int ID;
   int Chinese, English, math, science;
   int total;
} Grade;
void sortGrade(Grade *gList, int n);
#endif
