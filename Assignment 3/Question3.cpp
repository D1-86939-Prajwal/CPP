#include <iostream>
using namespace std;

class Stack {
private:
    int* stackArray;   // Pointer to the stack array
    int top;           // Index of the top element
    int maxSize;       // Maximum size of the stack

public:
    // Constructor with default size of 5
    Stack(int size = 5) : maxSize(size), top(-1) {
        stackArray = new int[maxSize];
    }

    // Destructor to deallocate memory
    ~Stack() {
        delete[] stackArray;
    }

    // Function to push an element onto the stack
    void push(int value) {
        if (isFull()) {
            cout << "Stack is full!" << endl;
        } else {
            stackArray[++top] = value;
        }
    }

    // Function to pop an element from the stack
    int pop() {
        if (isEmpty()) {
            cout << "Stack is empty!" << endl;
            return -1;  // Error value
        } else {
            return stackArray[top--];
        }
    }

    // Function to peek at the top element
    int peek() const {
        if (isEmpty()) {
            cout << "Stack is empty!" << endl;
            return -1;  // Error value
        } else {
            return stackArray[top];
        }
    }

    // Function to check if the stack is empty
    bool isEmpty() const {
        return top == -1;
    }

    // Function to check if the stack is full
    bool isFull() const {
        return top == maxSize - 1;
    }

    // Function to print the stack elements
    void print() const {
        if (isEmpty()) {
            cout << "Stack is empty!" << endl;
        } else {
            cout << "Stack elements: ";
            for (int i = 0; i <= top; i++) {
                cout << stackArray[i] << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    Stack myStack(3);  // Create a stack with a size of 3

    myStack.push(10);
    myStack.push(20);
    myStack.push(30);
    myStack.push(40);  // This should show an error message since the stack is full

    myStack.print();

    cout << "Top element is: " << myStack.peek() << endl;

    cout << "Popped element is: " << myStack.pop() << endl;

    myStack.print();

    return 0;
}
