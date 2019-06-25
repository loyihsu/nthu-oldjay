// Problem: http://140.114.86.238/problem/10949/
#include "function.h"

int maxValue(Node *tree)
{
    int rootmax = 0, leftmax = 0, rightmax = 0, tempr = 0, templ = 0;
    int maximum = 0;
    Node *temp;
    if (tree != NULL)
    {
        rootmax = tree->data;
    }
    
    if (tree->left != NULL)
    {
        for (temp = tree->left; temp != NULL; temp = temp->left)
        {
            if (temp->data > leftmax)
            {
                leftmax = temp->data;
            }
            if (temp->right != NULL)
            {
                tempr = maxValue(temp->right);
                if (tempr > leftmax)
                    leftmax = tempr;
            }
        }
    }
    
    if (tree->right != NULL)
    {
        for (temp = tree->right; temp != NULL; temp = temp->right)
        {
            if (temp->data > rightmax)
            {
                rightmax = temp->data;
            }
            if (temp->left != NULL)
            {
                templ = maxValue(temp->left);
                if (templ > leftmax)
                    rightmax = templ;
            }
        }
    }
    
    if (rootmax > maximum)
        maximum = rootmax;
    
    if (rightmax > maximum)
        maximum = rightmax;
    
    if (leftmax > maximum)
        maximum = leftmax;
    
    return maximum;
}
