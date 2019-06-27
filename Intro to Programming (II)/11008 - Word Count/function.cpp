// Problem: http://140.114.86.238/problem/11008
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "function.h"

void WordCount::readWords()
{
    numberOfTotalWords = 0;
    
    while (cin >> words[numberOfTotalWords])
    {
        numberOfTotalWords++;
    }
    
    return;
}

int compare(const void *a, const void *b)
{
    const string *ia = (const string *)a;
    const string *ib = (const string *)b;
    if (*ia > *ib) return 1;
    else if (*ia < *ib) return -1;
    else return 0;
}

void WordCount::sortWords()
{
    qsort(words, numberOfTotalWords, sizeof(string), compare);
    
    return;
}

void WordCount::countWords()
{
    numberOfDiffWords = 0;
    
    int i, j = 0;
    
    for (i = 0; i < numberOfTotalWords; i++)
    {
        if (words[i] != words[i+1])
        {
            numberOfDiffWords++;
            
        }
    }
    
    diffwords = new string[numberOfTotalWords];
    counting = (int*)calloc(numberOfTotalWords, sizeof(int));
    
    
    for (i = 0; i < numberOfTotalWords; i++)
    {
        if (words[i] != words[i+1])
        {
            diffwords[j] = words[i];
            j++;
        }
    }
    
    for (i = 0; i < numberOfDiffWords; i++)
    {
        for (j = 0; j < numberOfTotalWords; j++)
        {
            if (diffwords[i] == words[j])
            {
                counting[i]++;
            }
        }
    }
    
    return;
}

void WordCount::dumpResult()
{
    int i;
    
    for (i = 0; i < numberOfDiffWords; i++)
        std::cout << diffwords[i] << " " << counting[i] << "\n";
    
    return;
}


