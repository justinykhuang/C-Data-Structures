#include "LinkedList.cpp"
#include <iostream>

int main (){
    LinkedList list;

    std::cout << list.isEmpty() << std::endl;

    list.insert(2);
    list.insert(7);
    list.insert(10);
    list.insert(5);

    list.printList();

    list.remove(100);
    list.remove(2);

    list.printList();
    std::cout << list.isEmpty() << std::endl;

}