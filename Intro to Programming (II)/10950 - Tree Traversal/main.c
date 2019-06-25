#include <stdio.h>
#include <stdlib.h>
#include "function.h"

int main(void)
{
	int *in, *pre, n, i;
	scanf("%d", &n);// get the size of tree
	in = (int *) malloc(n * sizeof(int));//allocate space for inorder
	pre = (int *) malloc(n * sizeof(int));// allocate space for preorder
	for(i=0; i<n; i++)// read in inorder
		scanf("%d", &in[i]);
	for(i=0; i<n; i++)// read in pre-order
		scanf("%d", &pre[i]);

	Node *root = constructTree(in, pre, 0, n-1);// construct trr
	inorder(root);
	printf("\n");
	postorder(root);
	destroyTree(root);// clean up
	free(in);
	free(pre);

	return 0;
}

int idxSearch(int arr[], int strt, int end, int value)
{
	int i;
	for (i = strt; i <= end; i++)
	{
		if (arr[i] == value)
			return i;
	}
}

Node* newNode(int val)
{
	Node *node = (Node *)malloc(sizeof(Node));;
	node->data = val;
	node->left = node->right = NULL;
	return (node);
}

Node* constructTree(int inorder[], int preorder[], int inorder_start, int inorder_end)
{
	static int preorder_idx = 0;
	if(inorder_start > inorder_end)
		return NULL;
	Node *tree_node = newNode(preorder[preorder_idx++]);
	if(inorder_start == inorder_end)
		return tree_node;
	int inorder_idx = idxSearch(inorder, inorder_start, inorder_end, tree_node->data);
	tree_node->left = constructTree(inorder, preorder, inorder_start, inorder_idx-1);
	tree_node->right = constructTree(inorder, preorder, inorder_idx+1, inorder_end);

	return tree_node;
}

void destroyTree(Node *root)
{
	if(root != NULL)
	{
		destroyTree(root->left);
		destroyTree(root->right);
		free(root);
	}
}

