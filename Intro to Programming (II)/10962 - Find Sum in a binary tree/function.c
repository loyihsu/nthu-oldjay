// Problem: http://140.114.86.238/problem/10962/
#include "function.h"

int Sum(Node *root) {
    int left = 0, right = 0, roots = 0, sum = 0, templ = 0, tempr = 0;
    Node *temp = root->left;

    roots = root->data;
    
    while (temp != NULL) {
        left += temp->data;
        if (temp->right != NULL) {
            templ = Sum(temp->right);
            left += templ;
        }
        temp = temp->left;
    }
    
    Node *tempw = root->right;
    
    while (tempw != NULL) {
        right += tempw->data;
        if (tempw->left != NULL) {
            tempr = Sum(tempw->left);
            right += tempr;
        }
        tempw = tempw->right;
    }
    sum = right+left+roots;

    return sum;
}
