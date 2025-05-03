#include <iostream>
#include "BST.cpp" 

int main() {
    BinarySearchTree bst;  

    bst.isEmpty();

    int values[] = {5, 10, 12, 20, 22, 25, 28, 30, 32, 36, 38, 40, 42};

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
