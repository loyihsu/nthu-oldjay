// Problem: http://140.114.86.238/problem/10948/
#include <stdio.h>
#include "function.h"

Node* makeNode(int data) {
    Node *node = (Node*)malloc(sizeof(node));
    node->data = data;
    node->next = NULL;
    
    return node;
}

Node* createList() {
    int data;
    Node *node = NULL, *new, *temp = NULL, *prev = NULL;
    
    while (1) {
        scanf("%d", &data);
        if (data != -1) {
            new = makeNode(data);
            if (node == NULL) {
                node = new;
                temp = node;
            } else {
                while (temp != NULL) {
                    prev = temp;
                    temp = temp->next;
                }
                temp = new;
                prev->next = temp;
            }
        } else break;
    }
    return node;
}

void deleteNode(Node **nd, int data) {
    Node *cp;
    cp = (*nd);

    while (cp->next != NULL) {
        if (cp->next->data == data)
            cp->next = cp->next->next;
        else cp = cp->next;
    }
    
    if ((*nd)->data == data)
        (*nd) = (*nd)->next;
}
