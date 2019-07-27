// Problem: http://140.114.86.238/problem/11020/
#include <iostream>
#include <string.h>
#include "function.h"

//MARK: Constructors

Array_BST::Array_BST() {
    int i;
    for (i = 0; i <1025; i++)
        array[i] = 0;
    Height = 0;
}

List_BST::List_BST() {
    root = nullptr;
    Height = 0;
}

//MARK: Insert

void Array_BST::insert(const int &key) {
    int curheight = 0;
    int pos = 1;
    
    while (array[pos] != 0) {
        if (key == array[pos]) {
            return;
        } else {
            if (key > array[pos])
                pos = 2 * pos + 1;
            else
                pos = 2 * pos;
            curheight++;
        }
    }  
    array[pos] = key;
    curheight++;
    if (curheight > Height)
        Height = curheight;
}

void List_BST::insert(const int &key) {
    int curheight = 0;
    ListNode *temp = root, *prev = nullptr;

    if (root == nullptr) {
        root = createLeaf(key);
        curheight++;
    } else {
        while (temp != nullptr) {
            if (temp->key == key) {
                return;
            } else {
                prev = temp;
                if (key > temp->key)
                    temp = temp->right;
                else
                    temp = temp->left;
                curheight++;
            }
        }
    
        if (key > prev->key)
            prev->right = createLeaf(key);
        else
            prev->left = createLeaf(key);
        
        curheight++;
    }
    
    if (curheight > Height)
        Height = curheight;
}

ListNode* List_BST::createLeaf(int key) const {
    ListNode *output = new ListNode(key);
    output->left = nullptr;
    output->right = nullptr;
    return output;
}

//MARK: Search

bool Array_BST::search(const int &key) const {
    int pos = 1;
    
    while (array[pos] != 0) {
        if (array[pos] == key) {
            return true;
        } else {
            if (key > array[pos])
                pos = pos * 2 + 1;
            else
                pos = pos * 2;
        }
    }
    
    return false;
}

bool List_BST::search(const int &key) const {
    ListNode *temp = root;
    
    while (temp != nullptr) {
        if (temp->key == key) {
            return true;
        } else {
            if (key > temp->key)
                temp = temp->right;
            else
                temp = temp->left;
        }
    }
    
    return false;
}

void List_BST::deleteTree(ListNode *root) {
    if (root) {
        deleteTree(root->left);
        deleteTree(root->right);
        delete root;
    }
}
