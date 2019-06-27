// Problem: http://140.114.86.238/problem/10996
#include <iostream>
#include "function.h"

Josephus::Josephus()
{
    head = NULL;
    int i;
    for (i = 0; i < 50; i++)
        sequence[i] = 0;
    noOfPeople = 0;
}

Josephus::~Josephus()
{
    delete head;
}

Josephus::Josephus(const int &integer)
{
    head = NULL;
    int i;
    for (i = 0; i < 50; i++)
        sequence[i] = 0;

    noOfPeople = integer;
    generateFib(integer);
    generatecircularlinkedList(integer);
}

int Josephus::kill()
{
    
    Node *prev, *temp;
    
    prev = temp = head;
    
    int i, j = 0, k, remain = 0, flag = 0;
    
    while (temp != temp->next)
    {
        k = sequence[j++];
    
        if (k == 1 && flag == 0)
        {
            for (i = 0; i < noOfPeople; i++)
            {
                prev = temp;
                temp = temp->next;
            }
            prev->next = temp->next;
            noOfPeople--;
            temp = prev->next;
            flag = 1;
        } else {
            remain = k % noOfPeople;
            if (remain == 0)
                remain = noOfPeople;
            for (i = 0; i < remain - 1; i++)
            {
                prev = temp;
                temp = temp->next;
            }
            prev->next = temp->next;
            noOfPeople--;
            temp = prev->next;
        }
    }
    
    return temp->number;
}

void Josephus::generatecircularlinkedList(const int &number)
{
    Node *temp = NULL;
    
    for (int i = 1; i <= number; i++)
    {
        if (head == NULL)
            head = new Node(i);
        else {
            temp = head;
            while (temp->next != NULL)
            {
                temp = temp->next;
            }
            temp->next = new Node(i);
        }
    }
    
    temp = head;
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = head;
}

void Josephus::generateFib(const int &number)
{
    sequence[0] = 1;
    sequence[1] = 1;
    
    for (int i = 2; i < number; i++)
        sequence[i] = sequence[i-1] + sequence[i-2];
    
    return;
}


