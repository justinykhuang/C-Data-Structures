#include <iostream>
#include "BST.cpp" 

int main() {
    BinarySearchTree bst;  

    bst.isEmpty();

   int values[] = {25, 20, 10, 5, 12, 22, 36, 30, 28, 40, 32, 38, 42};


    for (int i = 0; i < 13; i++) {
        bst.insert(values[i]);
    }

    bst.isEmpty();

    std::cout << "In-order traversal of the tree:" << std::endl;
    bst.printInOrder();  
    bst.remove(5);
    bst.printInOrder();  
    bst.remove(10);
    bst.printInOrder();  
    bst.remove(25);
    bst.printInOrder();  

}
