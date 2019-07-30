// Problem: http://140.114.86.238/problem/10966/
#include <stdio.h>
#include <stdlib.h>
#include "function.h"

BTNode* EXPR() {
    BTNode *node, *right;
    char c;
    
    if (pos >= 0) {
        right = FACTOR();
        
        if (pos > 0) {
            c = expr[pos];
            if (c == '&' || c == '|') {
                node = makeNode(c);
                node->right = right;
                pos--;
                node->left = EXPR();
            } else {
                node = right;
            }
        } else { 
            node = right;
        }
    }
    return node;
}


BTNode* FACTOR() {
    char c;
    BTNode *node = NULL;
    
    if (pos >= 0) {
        c = expr[pos--];
        if (c >= 'A' && c <= 'D') {
            node = makeNode(c);
        } else if (c == ')') {
            node = EXPR();
            if (expr[pos--]!='(') {
                printf("Error!");
                freeTree(node);
            }
        }
    }

    return node;
}

BTNode* makeNode(char c) {
    BTNode *node;
    node = (BTNode*)malloc(sizeof(BTNode));
    int i;
    
    for (i = 0; i<NUMSYM; i++)
        if(c == sym[i]) node->data = i;
    
    node->left = NULL;
    node->right = NULL;
    
    return node;
}
