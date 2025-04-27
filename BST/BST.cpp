#include "BST.h"
#include <iostream>

BinarySearchTree::BinarySearchTree(){
    root = nullptr;
}

BinarySearchTree::~BinarySearchTree(){
    destroyTree(root);
    root = nullptr;
}

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

BinarySearchTree::Node* BinarySearchTree::findMax(Node* node){
    if (node == nullptr) {
        return nullptr;
       }
    while (node != nullptr){
        node = node -> rightChild;
    }
    return node;
}

void BinarySearchTree::insert(int value){ 
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

    else if ( temp -> data < value ){
        parent = temp;
        temp = temp -> rightChild;
    }

    else if ( temp -> data > value ){
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


void BinarySearchTree::InOrder(Node* node){
    if ( node == nullptr ){
        return;
    }
    InOrder(node -> leftChild);
    std::cout << node -> data << " ";
    InOrder(node -> rightChild);

}

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
    