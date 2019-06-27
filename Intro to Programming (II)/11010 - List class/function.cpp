// Problem: http://140.114.86.238/problem/
#include <iostream>
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
    if (firstPtr == nullptr)
    {
        firstPtr = new ListNode(value);
        lastPtr = firstPtr;
    } else {
        ListNode *newNode = new ListNode(value);
        newNode->nextPtr = firstPtr;
        firstPtr = lastPtr = newNode;
    }
}

void OWList::removeFromFront()
{
    if (firstPtr)
    {
        if (firstPtr->nextPtr)
        {
            firstPtr = firstPtr->nextPtr;
        } else {
            delete firstPtr;
            firstPtr = nullptr;
        }
        lastPtr = firstPtr;
    }
}

bool OWList::isEmpty() const
{
    if (firstPtr == nullptr)
        return true;
    else
        return false;
}

void OWList::print() const
{
    ListNode *temp = firstPtr;
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
    if (firstPtr == nullptr)
    {
        firstPtr = new ListNode(value);
        lastPtr = firstPtr;
        return;
    }
    
    while (lastPtr->nextPtr != nullptr)
    {
        lastPtr = lastPtr->nextPtr;
    }
    lastPtr->nextPtr = new ListNode(value);
    lastPtr = firstPtr;
}

void TWList::removeFromBack()
{
    if (lastPtr != nullptr)
    {
        ListNode *prev = lastPtr;
        while (lastPtr->nextPtr != nullptr)
        {
            prev = lastPtr;
            lastPtr = lastPtr->nextPtr;
        }

        prev->nextPtr = nullptr;
        delete lastPtr;
        lastPtr = firstPtr;
    }
}