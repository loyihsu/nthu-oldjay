// Problem: http://140.114.86.238/problem/10947/
#include "function.h"

int count;

Node* newNode(int data) {
    Node *new;
    new = (Node*)malloc(sizeof(Node));
    
    new->data = data;
    new->next = NULL;
    
    return new;
}

Node* createList() {
    int data = 0;
    Node *node = NULL, *new, *temp = NULL, *prev = NULL;
    new = (Node*)malloc(sizeof(Node));
    
    while (1) {
        scanf("%d", &data);
        if (data == -1)
            break;
        else {
            new = newNode(data);
            if (node == NULL)
            {
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
            count++;
        }
    }

    return node;
}


void deleteNode(Node ** nd, int data) {
    int flag = 0;
    Node *temp, *prev = NULL;

    if ((*nd) != NULL) {
        if (data == 1) {
            (*nd) = (*nd)->next;
            count--;
        } else if (data <= count) {
            temp = (*nd);
            for (flag = 0; flag < data-1; flag++) {
                prev = temp;
                temp = temp->next;
            }
            
            if (temp->next != NULL)
                prev->next = temp->next;
            else
                prev->next = NULL;
                
            count--;
        }
    }
}
