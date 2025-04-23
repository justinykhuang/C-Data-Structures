#ifndef Stack_h
#define Stack_h

class Stack {
    private:
    static const int Max_Size = 10;
    int arr[Max_Size];
    int top;
    int size;

    public:
    Stack();
    void push (int value);
    int peek();
    int pop();
    bool isEmpty();
    bool isFull();

};

#endif

