#include "Queue.h"
#include <iostream>

Queue_LinkedList::Queue_LinkedList(){
    head = nullptr;
    tail = nullptr;
}

Queue_LinkedList::~Queue_LinkedList(){
    while (head != nullptr){
        tail = head -> next;
        delete head;
        head = tail;
    }
}

void Queue_LinkedList::enqueue(int value){
    Node* newNode = new Node;
    newNode -> data = value;
    newNode -> next = nullptr;
 
    if (head == nullptr){
        head = newNode;
        tail = newNode;
    }
    else{
        tail -> next  = newNode;
        tail = newNode;
    }

}

int Queue_LinkedList::dequeue(){
    if ( head == nullptr ){
        std::cout << "List is empty, nothing to dequeue \n";
        return -1;
    }
    int value = head -> data;
    Node* temp = head;
    head = head -> next;
    delete temp;
    return value;

}

void Queue_LinkedList::printQueue(){
    Node* temp = head;
    if ( head == nullptr ){
        std::cout << "Queue is empty nothing to print \n";
        return;
    }
    else {
    std::cout << "Printing List of elementions from front to back \n";
        while ( temp != nullptr ){
            std::cout << temp -> data << std::endl ;
            temp = temp -> next;
        }
    }
}


bool Queue_LinkedList::isEmpty(){
    if ( head == nullptr ){
        return true;
    }
    return false;
}