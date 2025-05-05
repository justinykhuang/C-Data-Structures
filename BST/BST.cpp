#include "BST.h"
#include <iostream>

//constructor
BinarySearchTree::BinarySearchTree(){
    root = nullptr;
}

//destructor
BinarySearchTree::~BinarySearchTree(){
    destroyTree(root);
    root = nullptr;
}

//destructor helper recursive
void BinarySearchTree::destroyTree(Node* node){
    if (node == nullptr) {
        return;
    }

    destroyTree(node->leftChild);
    destroyTree(node->rightChild);
    delete node;
}

BinarySearchTree::Node* BinarySearchTree::findMin(Node* node){
   if (node == nullptr) {
    return nullptr;
   }
    while (node != nullptr){
        node = node -> leftChild;
    }
    return node;
}

//function to add elements into tree
void BinarySearchTree::insert(int value){ 
Node* newNode = new Node;
newNode -> data = value;
newNode -> leftChild = nullptr;
newNode -> rightChild = nullptr;
newNode -> parent = nullptr;

if ( root == nullptr ){
    root = newNode;
    return;
}

Node* temp = root;
Node* previous = root;

while (temp != nullptr){

    if ( value == temp -> data ){
        std::cout << "There is a duplicate value " << value << "in the tree \n" ;
        delete newNode;
        return;
    }

    else if ( temp -> data < value ){
        previous = temp;
        temp = temp -> rightChild;
    }

    else if ( temp -> data > value ){
        previous = temp;
        temp = temp -> leftChild;
    }

}
    if ( previous -> data > value ){
        previous -> leftChild = newNode;
        newNode -> parent = previous;
    }

    else if ( previous -> data < value ){
        previous -> rightChild = newNode;
        newNode -> parent = previous;
    }
}
//finding the node of specified value
BinarySearchTree::Node* BinarySearchTree::find(int value){
    Node* temp = root;
    while (temp != nullptr) {
        if (temp->data == value) {
            return temp;
        } else if (value < temp->data) {
            temp = temp->leftChild;
        } else {
            temp = temp->rightChild;
        }
    }
    return nullptr; 
}

void BinarySearchTree::treeConnector(Node* replace, Node* replaceParent, Node* replaceNode){
    //handle root node case
    if (replaceParent == nullptr){
        root = replaceNode;
        return;
    }
    //handle non-root case where parent has left child or right child 
    if (replaceParent -> rightChild == replace){
        replaceParent -> rightChild = replaceNode;
    }
    else {
        replaceParent -> leftChild = replaceNode;
    }
    if (replaceNode != nullptr){
        replaceNode -> parent = replaceParent;
    }
}

//handle removal of nodes based on int value
void BinarySearchTree::remove(int value){
    Node* replace = find(value);
    
    if (replace == nullptr){
        std::cout << "The value does not exist";
        return;
    }
    Node* replaceParent = replace -> parent;

    //leaf node
    if (replace -> leftChild == nullptr && replace -> rightChild == nullptr){ 
        treeConnector(replace, replaceParent, nullptr);
        delete replace;   
        return; 
    }
    //left child node
    else if ( replace -> leftChild != nullptr && replace -> rightChild == nullptr){ 
        treeConnector(replace, replaceParent, replace -> leftChild);
        delete replace;
        return;
    }
    //right child node
    else if ( replace -> leftChild == nullptr && replace -> rightChild != nullptr){ 
        treeConnector(replace, replaceParent, replace -> rightChild);
        delete replace;
        return;
    }
    //two children node
    else {
        Node* minNode = findMin(replace->rightChild);
        replace->data = minNode->data;
        remove(minNode->data);
        return;
    }

}   


//prints the BST in-order
void BinarySearchTree::InOrder(Node* node){
    if ( node == nullptr ){
        return;
    }
    InOrder(node -> leftChild);
    std::cout << node -> data << " ";
    InOrder(node -> rightChild);

}

//funcion call without input
void BinarySearchTree::printInOrder() {
    InOrder(root);
    std::cout << std::endl;
}


bool BinarySearchTree::isEmpty(){
    if ( root == nullptr ){
        std::cout << "The tree is Empty \n";
        return true;
    }
    std::cout << "The tree has elements \n";
    return false;
}
    