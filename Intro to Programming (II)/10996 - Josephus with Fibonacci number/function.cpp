// Problem: http://140.114.86.238/problem/10996
#include <stdio.h>
#include "function.h"
#include <stdlib.h>
#include <iostream>

int flag = 0;
int remain = 0;

int Josephus::kill()
{
    Node *p, *q;
    int i, j = 0;
    q = p = head;
    long long k;
    
    while (p->next != p)
    {
        k = sequence[j++];
        
        if (k == 1 && flag == 0)
        {
            for (i = 0; i < noOfPeople; i++)
            {
                q = p;
                p = p->next;
            }
            q->next = p->next;
            noOfPeople--;
            p = q->next;
            flag = 1;
        } else {
            remain = k % noOfPeople;
            if (remain == 0)
                remain = noOfPeople;
            for (i = 0; i < remain - 1; i++)
            {
                q = p;
                p = p->next;
            }
            q->next = p->next;
            p = q->next;
            noOfPeople--;
        }
    }
    
    return p->number;
}

Josephus::Josephus()
{
    int i;
    for (i = 0; i < 10005; i++)
    {
        sequence[i] = 0;
    }
}

Josephus::~Josephus()
{
    free(head);
}

Josephus::Josephus(const int &number)
{
    flag = 0;
    head = NULL;
    noOfPeople = number;
    generatecircularlinkedList(number);
    generateFib(number);
}

void Josephus::generatecircularlinkedList(const int &number)
{
    int i;
    Node *temp = NULL, *temp1;
    for (i = 1; i <= number; i++)
    {
        temp = (Node*)malloc(sizeof(Node));
        *temp = Node(i);
        if (head == NULL)
        {
            head = temp;
        } else {
            temp1 = head;
            while (temp1->next != NULL)
            {
                temp1 = temp1->next;
            }
            temp1->next = temp;
        }
    }
    temp->next = head;
}

void Josephus::generateFib(const int &number)
{
    int i;
    sequence[0] = 1; sequence[1] = 1;
    for (i = 2; i < number; i++)
    {
        sequence[i] = sequence[i-1] + sequence[i-2];
    }
    return;
}

