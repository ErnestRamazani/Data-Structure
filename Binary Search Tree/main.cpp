#include <iostream>
#include "node.h"

using namespace std;

//Main function 
int main() {

    int kSmallest;
    Node* root = NULL;

    //Drawing the tree

    cout << "The following Binary Tree is created" << endl;
    cout << "        6" << endl;
    cout << "      /   \ " << endl;
    cout << "    17     20" << endl;
    cout << "   /  \ " << endl;
    cout << " 41    45 " << endl;
    cout << "    /  \ " << endl;
    cout << "   52  57 " << endl;
    cout << "  /  \ " << endl;
    cout << " 65  71 " << endl;
    cout << "  /  \ " << endl;
    cout << " 76  87" << endl;
    cout << "    /  \ " << endl;
    cout << "   92  95 " << endl;
    cout << "    \ " << endl;
    cout << "    99 " << endl;

    cout << "Inorder Traversal of the BST" << endl;
    //Array to create the tree 
    int treeArray[] = { 6,17,20,41,45,52,57,65,71,76,87,92,95,99 };
    //Printing the Tree
    for (int j = 0; j < 14; j++) {
        cout << treeArray[j] << endl;
    }
    //Inserting element of the array in the tree 
    for (int i = 0; i < 14; i++) {
        root = insertNode(root, treeArray[i]);
    }

    //Taking user input for the Kth smallest and printing the result 
    cout << "Enter the number that return the value of the Kth Number" << endl;
    cin >> kSmallest;
    cout << KSmall(root, kSmallest) << " is the Kth smallest number"<<endl;
    return 0;
}