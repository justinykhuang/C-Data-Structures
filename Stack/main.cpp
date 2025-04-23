
#include <iostream>
#include "Stack.h"
#include "Stack.cpp"

int main() {
    Stack s;
    s.push(10);
    s.push(20);
    s.push(30);

    std::cout << "Top element: " << s.peek() << "\n";
    std::cout << "Popped: " << s.pop() << "\n";
    std::cout << "Now top: " << s.peek() << "\n";

    return 0;
}
