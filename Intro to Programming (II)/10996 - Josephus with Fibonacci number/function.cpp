// Problem: http://140.114.86.238/problem/10996
#include <iostream>
#include "function.h"

Josephus::Josephus() {
    for (int i = 0; i < 50; i++)
        sequence[i] = 0;
    noOfPeople = 0;
    head = nullptr;
}

Josephus::~Josephus() {
    for (int i = 0; i < 50; i++)
        sequence[i] = 0;
    noOfPeople = 0;
    head = nullptr;
}

Josephus::Josephus(const int &no) {
    for (int i = 0; i < 50; i++)
        sequence[i] = 0;
    noOfPeople = no;
    head = nullptr;
    
    generateFib(no);
    generatecircularlinkedList(no);
}

int Josephus::kill() {
    Node *prev, *temp;
    int k = 0, i = 0, j = 0, flag = 0, remain = 0;

    temp = prev = head;

    while (temp != temp->next) {
        k = sequence[j++];
        
        if (k == 1 && flag == 0) {
            for (i = 0; i < noOfPeople; i++) {
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
            
            for (i = 0; i < remain - 1; i++) {
                prev = temp;
                temp = temp->next;
            }
            
            prev->next = temp->next;
            temp = prev->next;
            noOfPeople--;
        }
    }
    
    return temp->number;
}

void Josephus::generatecircularlinkedList(const int &no) {
    for (int i = 1; i <= no; i++) {
        if (head == nullptr) {
            head = new Node(i);
        } else {
            Node *temp = head;
            while (temp->next != nullptr)
                temp = temp->next;
            
            temp->next = new Node(i);
        }
    }
    
    Node *temp = head;
    while (temp->next != nullptr)
        temp = temp->next;

    temp->next = head;    
}

void Josephus::generateFib(const int &no) {
    int pos = 0;
    sequence[0] = 1;
    sequence[1] = 1;
    
    for (pos = 2; pos < 50; pos++)
        sequence[pos] = sequence[pos-1] + sequence[pos-2];
}
