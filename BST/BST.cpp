#include "BST.h"
#include <iostream>

BinarySearchTree::BinarySearchTree(){
    root = nullptr;
}

BinarySearchTree::~BinarySearchTree(){\
    
}

void BinarySearchTree::insert( int value ){ 
Node* newNode = new Node;
newNode -> data = value;
newNode -> leftChild = nullptr;
newNode -> rightChild = nullptr;

if ( root == nullptr ){
    root = newNode;
    return;
}

Node* temp = root;
Node* parent = root;

while (temp != nullptr){

    if ( value == temp -> data ){
        std::cout << "There is a duplicate value " << value << "in the tree \n" ;
        delete newNode;
        return;
    }

    else if ( temp -> data > value ){
        parent = temp;
        temp = temp -> rightChild;
    }

    else if ( temp -> data < value ){
        parent = temp;
        temp = temp -> leftChild;
    }

}
    if ( parent -> data > value ){
        parent -> leftChild = newNode;
    }

    else if ( parent -> data < value ){
        parent -> rightChild = newNode;
    }
}

void BinarySearchTree::printTree(){
     
}

bool BinarySearchTree::isEmpty(){
    if ( root == nullptr ){
        std::cout << "The tree is Empty \n";
        return true;
    }
    std::cout << "The tree has elements \n";
    return false;
}
    