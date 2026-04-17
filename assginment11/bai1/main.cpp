#include <iostream>
#include "Stack.hpp"
#include "../common/InputHelper.hpp"
using namespace std;

int main() {
    Stack stack;
    Student student;
    int addCount, removeCount;

    cout << "===== STACK MANAGEMENT =====\n";

    addCount = InputHelper::inputIntInRange("Enter number of students to add: ", 1, 100);

    cout << "\n--- ADD STUDENTS TO STACK ---\n";
    for (int i = 0; i < addCount; i++) {
        if (stack.isFull()) {
            cout << "Stack is full. Cannot add more students.\n";
            break;
        }

        cout << "\nStudent " << i + 1 << ":\n";
        student.input();
        stack.push(student);
    }

    cout << "\nCurrent stack:\n";
    stack.display();

    removeCount = InputHelper::inputIntInRange("\nEnter number of students to remove: ", 1, 100);

    cout << "\n--- REMOVE STUDENTS FROM STACK ---\n";
    for (int i = 0; i < removeCount; i++) {
        if (stack.isEmpty()) {
            cout << "Stack is empty. Cannot remove more students.\n";
            break;
        }

        if (stack.pop(student)) {
            cout << "Removed: ";
            student.output();
        }
    }

    cout << "\nStack after removing:\n";
    stack.display();

    return 0;
}