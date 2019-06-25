// Problem: http://140.114.86.238/problem/10966/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "function.h"

BTNode* makeNode(char c)
{
    int i;
    BTNode *node = (BTNode*)malloc(sizeof(BTNode));
    for (i = 0; i < NUMSYM; i++)
        if (c==sym[i]) node->data = i;
    node->left = NULL;
    node->right = NULL;
    return node;
}

BTNode* factor()
{
    char c;
    BTNode *node = NULL;
    
    if (pos >= 0)
    {
        c = expr[pos--];
        if (c >= 'A' && c <= 'D')
        {
            node = makeNode(c);
        } else if (c == ')')
        {
            node = EXPR();
            if (expr[pos--] != '(')
            {
                printf("error!");
                freeTree(node);
            }
        }
    }
    return node;
}

BTNode* EXPR()
{
    //declare
    BTNode *node = NULL, *right = NULL;
    char c;
    
    if (pos >= 0)
    {
        right = factor();
        
        if (pos > 0)
        {
            c = expr[pos];
            if (c == '&' || c == '|')
            {
                node = makeNode(c);
                node->right = right;
                pos--;
                node->left = EXPR();
            } else node = right;
        } else node = right;
    }
    return node;
}
