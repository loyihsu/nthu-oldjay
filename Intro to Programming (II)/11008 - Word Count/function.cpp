// Problem: http://140.114.86.238/problem/11008
#include <iostream>
#include <stdlib.h>
#include "function.h"

void WordCount::readWords()
{
    numberOfTotalWords = 0;
    while (cin >> words[numberOfTotalWords])
        numberOfTotalWords++;
    
    return;
}

int cmp(const void *a, const void *b)
{
    const string *ia = (const string *)a;
    const string *ib = (const string *)b;
    
    if (*ia > *ib) return 1;
    else if (*ia == *ib) return 0;
    else return -1;
}

void WordCount::sortWords()
{
    qsort(words, numberOfTotalWords, sizeof(string), cmp);
}

void WordCount::countWords()
{
    diffwords = new string[numberOfTotalWords];
    counting = (int*)calloc(numberOfTotalWords, sizeof(int));
    
    numberOfDiffWords = 0;
    int i, j, index = 0;
    
    for (i = 0; i < numberOfTotalWords; i++)
        if (words[i] != words[i+1])
        {
            numberOfDiffWords++;
            diffwords[index++] = words[i];
        }
    
    for (i = 0; i < numberOfTotalWords; i++)
    {
        for (j = 0; j < numberOfDiffWords; j++)
        {
            if (words[i] == diffwords[j])
                counting[j]++;
        }
    }
    
    
}

void WordCount::dumpResult()
{
    int i;
    for (i = 0; i < numberOfDiffWords; i++)
    {
        std::cout << diffwords[i] << " " << counting[i] << "\n";
    }
        
}