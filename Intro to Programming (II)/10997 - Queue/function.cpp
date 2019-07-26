// Problem: http://140.114.86.238/problem/10997
#include <iostream>
#include <string.h>
#include "function.h"

List_queue::List_queue() {
    head = tail = nullptr;
}

List_queue::~List_queue() {
    head = tail = nullptr;
}

void List_queue::enqueue(const int &number) {
    ListNode *temp;
    if (head == nullptr) {
        head = tail = new ListNode(number);
    } else {
        temp = head;
        while (temp->nextPtr != nullptr)
            temp = temp->nextPtr;
        
        temp->nextPtr = new ListNode(number); 
    }
}

void List_queue::dequeue() {
    if (head) {
        if (head->nextPtr)
            head = head->nextPtr;
        else head = nullptr;
    }
}

void List_queue::print() {
    ListNode *temp = head;
    
    while (temp != nullptr) {
        std::cout << temp->data;
        if (temp->nextPtr != nullptr)
            std::cout << " ";
        temp = temp->nextPtr;
    }
}
