#include "Queue.cpp"


int main (){
    Queue_LinkedList WaitList;

    WaitList.isEmpty();
    WaitList.enqueue(2);
    WaitList.enqueue(4);
    WaitList.enqueue(6);
    WaitList.printQueue();

    WaitList.dequeue();
    WaitList.printQueue();


}