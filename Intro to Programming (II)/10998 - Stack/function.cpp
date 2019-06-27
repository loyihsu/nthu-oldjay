// Problem: http://140.114.86.238/problem/10998/
#include <iostream>
#include <string.h>
#include "function.h"

List_stack::List_stack()
{
    head = tail = nullptr;
}

List_stack::~List_stack()
{
    head = tail = nullptr;
}

void List_stack::push(const int &number)
{
    ListNode *temp;
    
    if (head == nullptr)
    {
        head = tail = new ListNode(number);
    } else {
        temp = head;
        while (temp->nextPtr != nullptr)
        {
            temp = temp->nextPtr;
        }
        temp->nextPtr = new ListNode(number);
        temp->nextPtr->prevPtr = temp;
    }
}

void List_stack::pop()
{
    if (head)
    {
        if (head->nextPtr != nullptr)
        {
            ListNode *temp, *prev;
        
            temp = prev = head;
        
            while (temp->nextPtr != nullptr)
            {
                prev = temp;
                temp = temp->nextPtr;
            }
    
            prev->nextPtr = nullptr;
        } else {
            head = nullptr;
        }
    }
}

void List_stack::print()
{
    ListNode *temp = head;
    if (temp)
    {
        while (temp->nextPtr != nullptr)
            temp = temp->nextPtr;
        
        while (temp != nullptr)
        {
            std::cout << temp->data;
            if (temp->prevPtr != nullptr)
                std::cout << " ";
            temp = temp->prevPtr;
        }
    }
}