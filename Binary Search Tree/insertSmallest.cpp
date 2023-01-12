#include <iostream>
#include "node.h"

using namespace std;
// Creating Binary Search tree node 
Node* newNode(int item)
{
    Node* temp = new Node;
    temp->key = item;
    temp->left = temp->right = NULL;
    return temp;
}

//This function insert a new node to the tree
//This function takes two arguments, one is the key, the other is a pointer to the node

Node* insertNode(Node* node, int key){
    //Return new node when the tree is empty 
    if (node == NULL) {
        return newNode(key);
    }
    //If the tree is not empty, keep adding new nodes
    if (key < node->key) {
        node->left = insertNode(node->left, key);
    }
    else {
        node->right = insertNode(node->right, key);
    }
   //return the nod pointer 
    return node;
}

//This function find the KSmallest element by traversing 
//the tree using the inorder traversal method 
//This function takes two arguments
int KSmall(Node* root, int k) {

    //starting the counter at 0
    static int counter = 0;

    // Return -1 if empty 
    if (root == NULL) {
        return -1;
    }


    // left subtree 
    int left = KSmall(root->left, k);

    // If left subtree has k nodes, then 
    // root must be kth node 
    if (left != -1) {
        return left;
    }
    counter++;

    // If counter is equal to k, then this is the Kth smallest node
    if (counter == k) {
        return root->key;
    }
    // right subtree 
    return KSmall(root->right, k);
}
