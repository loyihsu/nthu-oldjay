#include <stdio.h>
#include <stdlib.h>
#include "function.h"
#define change(x) ptr = gList[j].x; gList[j].x = gList[j+1].x; gList[j+1].x = ptr;

void sortGrade(Grade *gList, int n)
{
    int i, j;
    int ptr;
    for (i = 0; i<n; i++)
    {
        gList[i].total = gList[i].Chinese + gList[i].English + gList[i].math + gList[i].science;
    }
    
    for (i = 0; i < n-1; i++)
    {
        for (j = 0; j < n-1-i; j++)
        {
            if(gList[j].total < gList[j+1].total)
            {
                change(total)
                change(ID)
                change(Chinese)
                change(English)
                change(math)
                change(science)
            } else if (gList[j].total == gList[j+1].total)
            {
                if(gList[j].Chinese < gList[j+1].Chinese)
                {
                    change(total)
                    change(ID)
                    change(Chinese)
                    change(English)
                    change(math)
                    change(science)
                } else if (gList[j].Chinese == gList[j+1].Chinese)
                {
                    if(gList[j].English < gList[j+1].English)
                    {
                        change(total)
                        change(ID)
                        change(Chinese)
                        change(English)
                        change(math)
                        change(science)
                    } else if (gList[j].English == gList[j+1].English) {
                        if(gList[j].math < gList[j+1].math)
                        {
                            change(total)
                            change(ID)
                            change(Chinese)
                            change(English)
                            change(math)
                            change(science)
                        } else if (gList[j].math == gList[j+1].math) {
                            if(gList[j].science < gList[j+1].science)
                            {
                                change(total)
                                change(ID)
                                change(Chinese)
                                change(English)
                                change(math)
                                change(science)
                            } else if (gList[j].science == gList[j+1].science)
                            {
                                if(gList[j].ID > gList[j+1].ID)
                                {
                                    change(total)
                                    change(ID)
                                    change(Chinese)
                                    change(English)
                                    change(math)
                                    change(science)
                                }
                            }
                        }
                    }
                }
            }
        }
    }
}
