// Problem: http://140.114.86.238/problem/10576/
#include <iostream>
#include <stdlib.h>

struct Node
{
    Node *prev;
    Node *next;
    long long id;
};

int main(void)
{
    std::ios::sync_with_stdio(false);
    std::string command;
    Node *root = nullptr, *head;
    
    long long a, b;
    long long N, i;
    
    std::cin >> N;
    
    head = (Node*)malloc(sizeof(Node) * (N+1));
    
    for (i = 1; i <= N; i++)
    {
        if (root == nullptr)
        {
            root = &head[i];
            head[i].id = i;
            head[i].next = nullptr;
            head[i].prev = nullptr;
        } else {
            head[i].id = i;
            head[i].prev = &head[i-1];
            head[i-1].next = &head[i];
            head[i].next = nullptr;
        }
    }
    
    while (std::cin >> command, command != "Exit")
    {
        std::cin >> a >> b;
        if(head[a].next==&head[b]) continue;
        
        Node *newHead = head[a].next;
        Node *breakPoint = head[b].prev;
        Node *oldHead = root;
        
        newHead->prev = nullptr;
        breakPoint->next = oldHead;
        head[a].next = &head[b];
        head[b].prev = &head[a];
        oldHead->prev = newHead;
        root = newHead;
    }
    
    Node *temp = root;
    
    while (temp)
    {
        std::cout << temp->id;
        if (temp->next)
        {
            std::cout << " ";
        }
        temp = temp->next;
    }
    
    std::cout << "\n";

}