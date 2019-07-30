// Problem: http://140.114.86.238/problem/10968/
#include <stdio.h>
#include "function.h"

void printInfix(Node *root) {
    if (root != NULL) {
        printInfix(root->left);
        printf("%c", root->data);
        if (root->right != NULL) {
            if (root->right->data != '&' && root->right->data != '|') {
                printInfix(root->right);
            } else {
                printf("(");
                printInfix(root->right);
                printf(")");
            }
        }
    }
}
