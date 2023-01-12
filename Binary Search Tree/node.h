#ifndef NODE_H_EXISTS
#define NODE_H_EXISTS
#include <iostream>
using namespace std;

//Creating the node Struct 
struct Node {
    int key;
    struct Node* left, * right;
};

//Declaring function to be used 
int KSmall(Node*, int);
Node* insertNode(Node*, int); 

#endif