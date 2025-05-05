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

void BinarySearchTree::remove(int value){
    Node* replace = find(value);
    
    if (replace == nullptr){
        std::cout << "The value does not exist";
        return;
    }

    Node* replaceParent = replace -> parent;
    if (replaceParent != nullptr){
        //leaf node
        if (replace -> leftChild == nullptr && replace -> rightChild == nullptr){ 
            if (replaceParent -> leftChild  == replace ){
            replaceParent -> leftChild = nullptr;
            }
            else {
            replaceParent -> rightChild = nullptr;
            }
        delete replace;   
        return; 
        }
        // left child node
        else if ( replace -> leftChild != nullptr && replace -> rightChild == nullptr){ 
            if (replaceParent -> rightChild  == replace ){
                replaceParent -> rightChild = replace -> leftChild;
                }
                else {
                replaceParent -> leftChild = replace -> leftChild;
                }
            delete replace;
            return;
        }
        // right child node
        else if ( replace -> leftChild == nullptr && replace -> rightChild != nullptr){ 
            if (replaceParent -> leftChild  == replace ){
                replaceParent -> leftChild = replace -> rightChild;
                }
                else {
                replaceParent -> rightChild = replace -> rightChild;
                }
            delete replace;
            return;
        }
        // two children node
        else if (replace -> leftChild != nullptr && replace -> rightChild != nullptr ){
            Node* minNode = findMin(replace -> rightChild);
            replaceParent = minNode -> parent;
                if (replaceParent -> leftChild == minNode ){
                    replaceParent -> leftChild = nullptr;
                }
                else {
                    replaceParent -> rightChild = nullptr;
                }
            replace -> data = minNode -> data;
            remove(minNode -> data);
            return;
        }  
    }
    if (replaceParent == nullptr) {
        // root is a leaf
        if (replace->leftChild == nullptr && replace->rightChild == nullptr) {
            root = nullptr;
            delete replace;
            return;
        }
    
        // root has only left child
        if (replace->leftChild != nullptr && replace->rightChild == nullptr) {
            root = replace->leftChild;
            root->parent = nullptr;
            delete replace;
            return;
        }
    
        // root has only right child
        if (replace->leftChild == nullptr && replace->rightChild != nullptr) {
            root = replace->rightChild;
            root->parent = nullptr;
            delete replace;
            return;
        }
    
        // root has two children
        if (replace->leftChild == nullptr && replace->rightChild != nullptr) {
        Node* minNode = findMin(replace->rightChild);
        replace->data = minNode->data;
        remove(minNode->data); 
        return;
        }
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
    