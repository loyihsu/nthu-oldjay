// Problem: http://140.114.86.238/problem/10997
#include <iostream>
#include <string.h>
#include <stdlib.h>
#include "function.h"

List_queue::List_queue()
{
    head = tail = NULL;
    return;
}

List_queue::~List_queue()
{
    head = NULL;
    tail = NULL;
    return;
}

void List_queue::enqueue(const int &number)
{
    
    ListNode *temp, *cur = NULL;
    temp = (ListNode*)malloc(sizeof(ListNode));
    
    *temp = ListNode(number);
    
    if (tail == NULL)
    {
        head = tail = temp;
    } else {
        cur = tail;
        while (cur->nextPtr != NULL)
            cur = cur->nextPtr;
        cur->nextPtr = temp;
    }
}

void List_queue::dequeue()
{
    if (head != NULL)
    {
        head = tail = head->nextPtr;
    }
    else
        head = tail = NULL;
    return;
}

void List_queue::print()
{
    while (head != NULL)
    {
        std::cout << head->data;
        if (head->nextPtr != NULL)
            std::cout << " ";
        head = head->nextPtr;
    }
    
    head = tail;
    
    return;
}
