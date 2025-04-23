#ifndef Queue_h
#define Queue_h

class Queue_LinkedList {
private:
    struct Node {
        int data;
        Node* next = nullptr;
    };

Node* head;
Node* tail;

public: 
    Queue_LinkedList();
    ~Queue_LinkedList();

    void enqueue(int value);
    int dequeue();
    void printQueue();
    bool isEmpty();

};
#endif