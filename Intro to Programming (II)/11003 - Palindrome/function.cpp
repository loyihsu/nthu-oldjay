// Problem: http://140.114.86.238/problem/11003
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include "function.h"

SimpleString::SimpleString(char *c, int a)
{
    if (ptr == NULL)
        ptr = (char*)malloc(sizeof(c));
    if (c != NULL)
        strcpy(ptr, c);
    size = a;
    return;
}

SimpleString::SimpleString(const SimpleString &SS)
{
    strcpy(ptr, SS.ptr);
    size = SS.size;
    return;
}

SimpleString::~SimpleString()
{
    size = 0;
    memset(ptr, 0, sizeof(char));
    return;
}

const SimpleString &SimpleString::operator=(const SimpleString &SS)
{
    if (&SS != this)
    {
        size = SS.size;
        if (ptr == NULL)
            ptr = (char*)malloc(sizeof(char));
        strcpy(ptr, SS.ptr);
    }
    return *this;
}

bool SimpleString::operator==(const SimpleString &string) const
{
    if (strcmp(ptr, string.ptr) == 0) return true;
    else return false;
}

void SimpleString::reverse()
{
    int i;
    SimpleString temp;
    
    temp.ptr = (char*)malloc(size*sizeof(char));
    
    for (i = 0; i < size; i++)
    {
        temp.ptr[i] = ptr[size-i-1];
    }
    
    strcpy(ptr, temp.ptr);
    
    return;
}
