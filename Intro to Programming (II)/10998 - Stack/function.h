#ifndef FUNCTION_H
#define FUNCTION_H
#include <iostream>

class ListNode
{
    friend class List_stack; //make List_stack a friend
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

class List_stack {
    public:
        List_stack();
        ~List_stack();
        void push(const int &);
        void pop();
        void print();
    private:
        ListNode *head;
        ListNode *tail;
};
#endif // FUNCTION_H
