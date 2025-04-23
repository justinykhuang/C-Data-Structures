#include "Stack.h"
#include <iostream>

Stack::Stack(){
    top = -1;
}

void Stack::push (int value){
    if (isFull()){
        return;
    }
    arr[++top] = value;

}
int Stack::peek(){
    if (isEmpty()){
        return -1;
    }
     return arr[top];
}

int Stack::pop(){
    if (isEmpty()){
        return -1;
    }
return arr[top--];
}

bool Stack::isEmpty(){   
    return top == -1;
}

bool Stack::isFull(){
    return top == Max_Size -1;
}



