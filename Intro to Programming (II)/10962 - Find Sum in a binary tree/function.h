#include <stdlib.h>
typedef struct treeNode {
    int data;
    struct treeNode *left;
    struct treeNode *right;
} Node;

int idxSearch(int arr[], int strt, int end, int value);
Node* newNode(int val);
Node* constructTree(int inorder[], int preorder[], int inorder_start, int inorder_end);
void destroyTree(Node *root);
int Sum(Node *root);
