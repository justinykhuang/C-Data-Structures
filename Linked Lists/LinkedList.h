#ifndef LinkedList_H
#define LinkedList_H
class LinkedList{
private:
    struct Node {
    int data;
    Node* next;
};

Node* head;

public:
    LinkedList();
    ~LinkedList();

    void insert(int value);
    bool isEmpty();
    bool remove(int value);
    void printList();

};
#endif