#ifndef FUNCTION_H_INCLUDED
#define FUNCTION_H_INCLUDED

#define SIZE 50
typedef struct{
    char Name[15];
    char Height[15];
    char Weight[15];
} Info;
void Find_Revise(Info* , int , char , int* );

#endif // FUNCTION_H_INCLUDED
