#include "Stack.hpp"
#include <iostream>
using namespace std;

Stack::Stack() {
    top = -1;
}

bool Stack::isEmpty() const {
    return top == -1;
}

bool Stack::isFull() const {
    return top == MAX - 1;
}

bool Stack::push(const Student& student) {
    if (isFull()) {
        cout << "Stack is full. Cannot add more students.\n";
        return false;
    }

    data[++top] = student;
    return true;
}

bool Stack::pop(Student& student) {
    if (isEmpty()) {
        cout << "Stack is empty. Cannot remove student.\n";
        return false;
    }

    student = data[top--];
    return true;
}

bool Stack::peek(Student& student) const {
    if (isEmpty()) {
        cout << "Stack is empty.\n";
        return false;
    }

    student = data[top];
    return true;
}

void Stack::display() const {
    if (isEmpty()) {
        cout << "Stack is empty.\n";
        return;
    }

    cout << "Current students in stack:\n";
    for (int i = top; i >= 0; i--) {
        data[i].output();
    }
}