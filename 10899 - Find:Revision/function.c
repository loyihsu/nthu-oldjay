// Problem: http://140.114.86.238/problem/10899/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "function.h"

#define SIZE 50


int compare (const void *a, const void *b);

void Find_Revise(Info*List, int num, char instr, int*isend)
{
    //declare
    char action[9];
    int index, i, out = 0;
    Info tmp[50];
    
    if (instr == 'F')
    {
        out = 0;
        //Find
        scanf("%s", action);
        
        for (i = 0; i < num; i++)
        {
            if (strstr(List[i].Name,action) || strstr(List[i].Height,action) || strstr(List[i].Weight,action))
            {
                tmp[out++] = List[i];
            }
        }
        
        qsort(tmp, out, sizeof(Info), compare);
        
        for (i = 0; i<out; i++) printf("%-10s%-8s%-8s\n", tmp[i].Name, tmp[i].Height, tmp[i].Weight);
        
        if (!out) printf("NOT FOUND\n");
    } else if (instr == 'R')
    {
        //Revise
        scanf("%i", &index);
        scanf("%s%s%s", List[index-1].Name, List[index-1].Height, List[index-1].Weight);
        for (i = 0; i<num; i++)
        {
            if (i != index-1)
            {
                if(!strcmp(List[index-1].Name, List[i].Name))
                {
                    memset(&List[index-1],0,sizeof(List[index]));
                    memset(&List[i],0,sizeof(List[i]));
                }
            }
        }
    } else if (instr == 'E' || instr == 'e')
    {
        //End
        *isend = 1;
        return;
    }
}

int compare (const void *a, const void *b)
{
    const Info *ia = (const Info *) a;
    const Info *ib = (const Info *) b;
    return strcmp(ia->Name, ib->Name);
}
