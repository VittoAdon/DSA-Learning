#include <iostream>
using namespace std;

class Stack {
private:
    int *arr;
    int capacity;
    int top;

public:
    // Constructor
    Stack(int size) {
        capacity = size;
        arr = new int[capacity];
        top = -1;
    }

    // Check whether stack is empty
    bool isEmpty() {
        return top == -1;
    }

    // Check whether stack is full
    bool isFull() {
        return top == capacity - 1;
    }

    // Push element onto stack
    void push(int value) {
        if (isFull()) {
            cout << "Stack Overflow!" << endl;
            return;
        }

        top++;
        arr[top] = value;
    }

    // Remove top element
    void pop() {
        if (isEmpty()) {
            cout << "Stack Underflow!" << endl;
            return;
        }

        cout << "Popped: " << arr[top] << endl;
        top--;
    }

    // Return top element
    int peek() {
        if (isEmpty()) {
            cout << "Stack is empty!" << endl;
            return -1;
        }

        return arr[top];
    }

    // Display stack
    void display() {
        if (isEmpty()) {
            cout << "Stack is empty!" << endl;
            return;
        }

        cout << "Stack: ";

        for (int i = top; i >= 0; i--) {
            cout << arr[i] << " ";
        }

        cout << endl;
    }

    // Destructor
    ~Stack() {
        delete[] arr;
    }
};

int main() {

    Stack stack(5);

    stack.push(10);
    stack.push(20);
    stack.push(30);

    stack.display();

    cout << "Top: " << stack.peek() << endl;

    stack.pop();

    stack.display();

    cout << "Top: " << stack.peek() << endl;

    stack.pop();
    stack.pop();

    stack.display();

    stack.pop();   // Underflow

    return 0;
}