// Problem: http://140.114.86.238/problem/10949/
#include <stdio.h>
#include <stdlib.h>
#include "function.h"

int maxValue(Node *tree)
{
    Node *lc, *rc;
    
    int output, temp1, temp2;
    
    if (tree)
    {
        int rootmax = tree->data;
        output = rootmax;
    }
    
    if (tree->left)
    {
        int leftmax = tree->left->data;
        for (lc = tree->left; lc != NULL; lc = lc->left)
        {
            if (lc->data > leftmax) leftmax = lc->data;
            if (lc->right)
            {
                temp1 = maxValue(lc->right);
                if (temp1 > leftmax) leftmax = temp1;
            }
        }
        if (leftmax > output) output = leftmax;
    }
    
    if (tree->right)
    {
        int rightmax = tree->right->data;
        
        for (rc = tree->right; rc != NULL; rc = rc->right)
        {
            if (rc->data > rightmax) rightmax = rc->data;
            if (rc->left)
            {
                temp2 = maxValue(rc->left);
                if (temp2 > rightmax) rightmax = temp2;
            }
        }
        
        if (rightmax > output) output = rightmax;
    }
    
    return output;
}
