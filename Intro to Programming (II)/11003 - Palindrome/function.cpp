// Problem: http://140.114.86.238/problem/11003
#include <iostream>
#include <cstring>
#include <cstdlib>
#include "function.h"

SimpleString::SimpleString(char *ch, int s)
{
    int size_;
    
    if (s > 0)
        size_ = 1;
    else {
        size_ = s;
    }
    
    if (ptr == nullptr)
        ptr = (char*)calloc(size_, sizeof(char));

    
    if (ch != nullptr)
        strcpy(ptr, ch);
    
    size = s;
}

SimpleString::SimpleString(const SimpleString &ss)
{
    if (ptr == nullptr)
        ptr = (char*)calloc(ss.size, sizeof(char));
    
    size = ss.size;
    strcpy(ptr, ss.ptr);
}

SimpleString::~SimpleString()
{
    memset(ptr, 0, sizeof(char));
    size = 0;
}

const SimpleString &SimpleString::operator=( const SimpleString &ss )
{
    if (&ss != this)
    {
        if (ptr == nullptr)
            ptr = (char*)calloc(ss.size, sizeof(char));
        strcpy(ptr, ss.ptr);
        size = ss.size;
    }
    
    return *this;
}

bool SimpleString::operator==( const SimpleString &ss ) const
{
    if (!strcmp(ptr,ss.ptr)) return true;
    else return false;
}

void SimpleString::reverse()
{
    char *temp = (char*)calloc(size, sizeof(char));
    int i;
    
    for (i = 0; i < size; i++)
    {
        temp[i] = ptr[size-1-i];
    }
    
    strcpy(ptr, temp);
}



