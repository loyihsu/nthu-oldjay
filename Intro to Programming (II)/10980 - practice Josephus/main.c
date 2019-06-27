// Problem: http://140.114.86.238/problem/10980/
#include <stdio.h>
#include <stdlib.h>

typedef struct _node
{
    int num;
    struct _node *next;
} Node;

void create();
int survivor(Node*, int);
Node* makeNode(int);

Node *head = NULL;
int number, skip;

int main(void)
{
    int survive;
    
    while (scanf("%d%d", &number, &skip) != EOF)
    {
        head = NULL;
        create();
        if (skip > 1)
            survive = survivor(head, skip);
        else if (skip == 1) {
            survive = number;
        } else {
            survive = 0;
        }
        printf("%d\n", survive);
    }
    
    return 0;
}

int survivor(Node* head, int k)
{
    Node *p, *q;
    int i;
    
    q = p = head;
    while (p->next != p)
    {
        for (i = 0; i < k - 1; i++)
        {
            q = p;
            p = p->next;
        }
        q->next = p->next;
        free(p);
        p = q->next;
    }
    head = p;
    
    return (p->num);
}

Node* makeNode(int i)
{
    Node *node;
    node = (Node*)malloc(sizeof(Node));
    node->num = i;
    node->next = NULL;
    return node;
}

void create()
{
    int i;
    Node *temp, *temp1;
    for (i = 1; i <= number; i++)
    {
        temp = makeNode(i);
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
