#ifndef BST_H
#define BST_H

class BinarySearchTree {
private:
    struct Node {
        int data;
        Node* leftChild;
        Node* rightChild;

    };

    Node* root;

public:

BinarySearchTree();
~BinarySearchTree();

void insert ( int value );
//void remove ( int value );
void printTree ();
bool isEmpty ();

};

#endif