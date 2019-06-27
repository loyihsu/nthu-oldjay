// Problem: http://140.114.86.238/problem/10972/
#include <stdio.h>
#include <stdlib.h>

typedef enum {ID_A, ID_B, ID_C, ID_D, OP_AND, OP_OR} TokenSet;
char sym[6] = "ABCD&|";

char expr[200];
int pos;

typedef struct _Node
{
    TokenSet data;
    struct _Node *left, *right;
} BTNode;

BTNode* EXPR();
BTNode* FACTOR();

void freeTree(BTNode* tree)
{
    free(tree);
}

BTNode* makeNode(char val)
{
    BTNode *node = (BTNode*)malloc(sizeof(BTNode));
    int i;
    for (i = 0; i < 6; i++)
        if (val == sym[i]) node->data = i;
    node->left = NULL;
    node->right = NULL;
    
    return node;
}

BTNode* FACTOR()
{
    char c;
    BTNode *node = NULL;
    
    
    if (pos >= 0)
    {
        c = expr[pos--];
        if (c >= 'A' && c <= 'D')
            node = makeNode(c);
        else if (c == ')')
        {
            node = EXPR();
            if (expr[pos--] != '(')
            {
                printf("Error!");
                freeTree(node);
            }
        }
    }
    return node;
}

BTNode* EXPR()
{
    char c;
    BTNode *node = NULL, *right = NULL;
    
    if (pos >= 0)
    {
        right = FACTOR();
        
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

void printWithoutPare(BTNode *root)
{
    if (root != NULL)
    {
        printWithoutPare(root->left);
        printf("%c", sym[root->data]);
        if (root->right != NULL)
        {
            if (root->right->data == OP_OR || root->right->data == OP_AND)
            {
                printf("(");
                printWithoutPare(root->right);
                printf(")");
            } else printWithoutPare(root->right);
        }
    }
}

int main(void)
{
    scanf("%s", expr);
    pos = strlen(expr) - 1;
    BTNode *node = EXPR();
    printWithoutPare(node);
    return 0;
}
