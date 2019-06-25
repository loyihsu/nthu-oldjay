// Problem: http://140.114.86.238/problem/10950/
#include <stdio.h>
#include <stdlib.h>
#include "function.h"

void inorder(Node *root)
{
    
    if (!root)
    {
        return;
    }
    
    inorder(root->left);
    
    printf("%d ", root->data);
    
    inorder(root->right);
}

void postorder(Node *root)
{
    if (!root)
    {
        return;
    }
    
    postorder(root->left);
    
    postorder(root->right);
    
    printf("%d ", root->data);
    
    return;
}
