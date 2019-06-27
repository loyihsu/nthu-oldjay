// Problem: http://140.114.86.238/problem/11020/
#include <iostream>
#include <string.h>
#include "function.h"

//MARK: Constructors

Array_BST::Array_BST()
{
    for (int i = 0; i < 1025; i++)  array[i] = 0;
    Height = 0;
}

List_BST::List_BST()
{
    root = nullptr;
    Height = 0;
}

//MARK: Array_BST functions

void Array_BST::insert(const int &number)
{
    int index = 1;
    int cur_hei_arr = 0;
    
    while (array[index] != 0)
    {
        if (array[index] == number)
        {
            return;
        } else {
            if (number < array[index])
                index *= 2;
            else
                index = 2 * index +1;
            cur_hei_arr++;
        }
    }
    
    array[index] = number;
    cur_hei_arr++;
    if (cur_hei_arr > Height)
        Height = cur_hei_arr;
}

bool Array_BST::search(const int &number) const
{
    int index = 1;
    
    while (array[index] != 0)
    {
        if (array[index] == number)
            return true;
        else if (number > array[index])
            index = index*2 + 1;
        else if (number < array[index])
            index *= 2;
    }
    
    return false;
}

//MARK: List_BST functions

void List_BST::insert(const int &number)
{
    int cur_height = 0;
    
    if (root == NULL)
    {
        root = createLeaf(number);
        cur_height++;
    } else {
        ListNode *temp = root, *prev = nullptr;
        
        while (temp != nullptr)
        {
            if (temp->key == number)
                return;
            else {
                prev = temp;
                if (number < temp->key)
                    temp = temp->left;
                else
                    temp = temp->right;
                cur_height++;
            }
        }
        
        if (number > prev->key)
            prev->right = createLeaf(number);
        else
            prev->left = createLeaf(number);
        
        cur_height++;
    }
    
    if (cur_height > Height)
        Height = cur_height;
    
    return;
}

bool List_BST::search(const int &number) const
{
    ListNode *temp = root;
    
    while (temp != nullptr)
    {
        if (temp->key == number)
        {
            return true;
        } else {
            if (number < temp->key)
            {
                temp = temp->left;
            } else {
                temp = temp->right;
            }
        }
    }
    
    return false;
}

ListNode* List_BST::createLeaf(int key) const
{
    ListNode *newNode = new ListNode(key);
    newNode->left = nullptr;
    newNode->right = nullptr;
    return newNode;
}

void List_BST::deleteTree(ListNode *root)
{
    if (root)
    {
        deleteTree(root->left);
        deleteTree(root->right);
        delete root;
    }
}