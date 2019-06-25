// Problem: http://140.114.86.238/problem/10945/
#include "function.h"

Node* makeNode(int data)
{
    Node *node;
    node = (Node*)malloc(sizeof(Node));
    node->data = data;
    node->next = NULL;
    
    return node;
}

void insert_increase_list(Node **node, int data)
{
    Node *new = NULL;
    new = makeNode(data);
    Node *temp = NULL, *prev = NULL;
    
    if (*node == NULL)
    {
        *node = new;
    } else {
        if (data < (*node)->data)
        {
            new->next = *node;
            *node = new;
        } else {
            temp = (*node);
            while (temp != NULL && temp->data < data)
            {
                prev = temp;
                temp = temp->next;
            }
            if (temp == (*node))
            {
                new->next = (*node);
                (*node) = new;
            } else if (temp != NULL)
            {
                prev->next = new;
                new->next = temp;
            } else {
                prev->next = new;
            }
        }
    }
}
