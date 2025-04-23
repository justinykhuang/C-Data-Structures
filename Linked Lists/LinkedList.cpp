#include <iostream>
#include "LinkedList.h"



LinkedList::LinkedList(){
    head = nullptr;
}

LinkedList::~LinkedList(){
    while (head != nullptr) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
}

void LinkedList::insert(int value){
    Node* newNode = new Node;
    newNode -> data = value;
    newNode -> next = nullptr;

        if ( head  == nullptr ){
            head = newNode;
        }
        else {
           Node* temp = head;
            while ( temp -> next != nullptr ){
                temp = temp -> next;
            }
            temp -> next = newNode;
        }
    
}

bool LinkedList::isEmpty(){
    if ( head == nullptr ){
        std::cout << "list is empty ";
        return true;
    }
    std::cout << "list is non empty ";
    return false;
}

bool LinkedList::remove(int value){
    if (head == nullptr) {
        std::cout << "List is empty" << std:: endl;
        return false;
    }

    Node* temp = head;
   
    if ( head -> data == value ){
        head = head -> next;
        delete temp;
        return true;
    }

     Node* leader = head -> next;

    while ( leader != nullptr ){

        if (leader -> data != value ){
            temp = leader;
            leader = leader -> next;
        }
        else {
            temp -> next = leader -> next;
            delete leader;
            return true;
        }
    }        
    std::cout << "Value " << value << " not found in Linked List \n";
    return false;

}

void LinkedList::printList(){
    Node* temp = head;
    std::cout << "Printing List of integers below \n" ;
    while ( temp != nullptr ){
        std::cout << temp -> data << std::endl;
        temp = temp -> next;
    }
}
