// Problem: http://140.114.86.238/problem/
#include <iostream>
#include <stdlib.h>
#include <string>
#include "function.h"

OWList::OWList()
{
    firstPtr = lastPtr = nullptr;
}

OWList::~OWList()
{
    firstPtr = lastPtr = nullptr;
}

void OWList::insertAtFront(const int &value)
{
    ListNode *newNode;
    newNode = (ListNode*)malloc(sizeof(ListNode));
    *newNode = ListNode(value);
    if (firstPtr == NULL)
    {
        firstPtr = lastPtr = newNode;
    } else {
        newNode->nextPtr = firstPtr;
        firstPtr = lastPtr = newNode;
    }
}

void OWList::removeFromFront()
{
    if (firstPtr != nullptr)
    {
        if (firstPtr->nextPtr != nullptr)
        {
            firstPtr = firstPtr->nextPtr;
            lastPtr = firstPtr;
        } else {
            firstPtr = nullptr;
            lastPtr = firstPtr;
        }
    }
}

bool OWList::isEmpty() const
{
    if (firstPtr == NULL)
        return true;
    else
        return false;
}

void OWList::print() const
{
    ListNode *temp;
    temp = firstPtr;
    
    while (temp != nullptr)
    {
        std::cout << temp->data;
        if (temp->nextPtr != nullptr)
            std::cout << " ";
        temp = temp->nextPtr;
    }
}

void TWList::insertAtBack(const int &value)
{
    ListNode *newNode;
    newNode = (ListNode*)malloc(sizeof(ListNode));
    *newNode = ListNode(value);
    if (firstPtr == NULL)
    {
        firstPtr = lastPtr = newNode;
    } else {
        ListNode *temp;
        temp = firstPtr;
        
        while (temp->nextPtr != nullptr)
        {
            temp = temp->nextPtr;
        }
        temp->nextPtr = newNode;
        
        lastPtr = firstPtr;
    }
}

void TWList::removeFromBack()
{
    if (firstPtr != nullptr)
    {
        if (firstPtr->nextPtr != nullptr)
        {
            ListNode *temp, *prev = firstPtr;
            temp = firstPtr;
            while (temp->nextPtr != nullptr)
            {
                prev = temp;
                temp = temp->nextPtr;
            }
            
            prev->nextPtr = NULL;
            lastPtr = nullptr;
        } else {
            firstPtr = nullptr;
            lastPtr = firstPtr;
        }
    }
}
