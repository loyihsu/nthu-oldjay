#ifndef FUNCTION_H
#define FUNCTION_H
#include <iostream>

class ListNode {
    friend class List_queue; //make List_queue a friend
    public:
        ListNode( const int &info ) //constructor
        : data( info ), nextPtr( NULL ), prevPtr( NULL )
        {
        } //end ListNode constructor
    private:
        int data; //data
        ListNode *nextPtr; // next node in list
        ListNode *prevPtr;
}; //end class ListNode

class List_queue {
    public:
        List_queue();
        ~List_queue();
        void enqueue(const int &);
        void dequeue();
        void print();
    private:
        ListNode *head;
        ListNode *tail;
};
#endif


