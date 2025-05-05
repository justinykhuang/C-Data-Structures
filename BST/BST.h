#ifndef BST_H
#define BST_H

class BinarySearchTree {
private:
    struct Node {
        int data;
        Node* leftChild;
        Node* rightChild;
        Node* parent;
    };

    Node* root;

    void destroyTree(Node* node);
    Node* findMin(Node* node);
    Node* find(int data);
    void InOrder(Node* node);
    void treeConnector(Node* parent, Node* child, Node* replaceNode);
    

public:

BinarySearchTree();
~BinarySearchTree();

void insert(int value);
void remove(int value);
void printInOrder();
bool isEmpty();


};

#endif