#include <iostream>
#include <string>
#include "TemplateStack.hpp"
#include "TemplateQueue.hpp"
#include "InputHelperbai3.hpp"
#include "../common/Student.hpp"

using namespace std;

// ===== Nhap du lieu theo tung kieu =====
void inputValue(int& value) {
    value = InputHelperbai3::inputInt("Enter integer value: ");
}

void inputValue(double& value) {
    value = InputHelperbai3::inputDouble("Enter double value: ");
}

void inputValue(Student& value) {
    cout << "Enter student information:\n";
    value.input();
}

// ===== Xuat du lieu theo tung kieu =====
void outputValue(const int& value) {
    cout << value << endl;
}

void outputValue(const double& value) {
    cout << value << endl;
}

void outputValue(const Student& value) {
    value.output();
}

// ===== Chay STACK voi kieu du lieu T =====
template <typename T>
void runStack() {
    TemplateStack<T> stack;
    T value;

    int count = InputHelperbai3::inputIntInRange("Enter number of elements to push: ", 1, 100);

    cout << "\n--- Input data into STACK ---\n";
    for (int i = 0; i < count; i++) {
        cout << "\nElement " << i + 1 << ":\n";
        inputValue(value);

        if (!stack.push(value)) {
            cout << "Stack is full. Cannot add more elements.\n";
            break;
        }
    }

    cout << "\n--- Output data from STACK (LIFO) ---\n";
    while (!stack.isEmpty()) {
        if (stack.pop(value)) {
            outputValue(value);
        }
    }
}

// ===== Chay QUEUE voi kieu du lieu T =====
template <typename T>
void runQueue() {
    TemplateQueue<T> queue;
    T value;

    int count = InputHelperbai3::inputIntInRange("Enter number of elements to enqueue: ", 1, 100);

    cout << "\n--- Input data into QUEUE ---\n";
    for (int i = 0; i < count; i++) {
        cout << "\nElement " << i + 1 << ":\n";
        inputValue(value);

        if (!queue.enqueue(value)) {
            cout << "Queue is full. Cannot add more elements.\n";
            break;
        }
    }

    cout << "\n--- Output data from QUEUE (FIFO) ---\n";
    while (!queue.isEmpty()) {
        if (queue.dequeue(value)) {
            outputValue(value);
        }
    }
}

int main() {
    int structureChoice;
    int typeChoice;

    cout << "===== BAI 3 - TEMPLATE STACK / QUEUE =====\n";

    do {
        cout << "\nChoose data structure:\n";
        cout << "1. Stack\n";
        cout << "2. Queue\n";
        cout << "0. Exit\n";
        structureChoice = InputHelperbai3::inputIntInRange("Your choice: ", 0, 2);

        if (structureChoice == 0) {
            cout << "Program ended.\n";
            break;
        }

        cout << "\nChoose data type:\n";
        cout << "1. int\n";
        cout << "2. double\n";
        cout << "3. Student\n";
        typeChoice = InputHelperbai3::inputIntInRange("Your choice: ", 1, 3);

        if (structureChoice == 1) {
            if (typeChoice == 1) {
                runStack<int>();
            } else if (typeChoice == 2) {
                runStack<double>();
            } else {
                runStack<Student>();
            }
        } else {
            if (typeChoice == 1) {
                runQueue<int>();
            } else if (typeChoice == 2) {
                runQueue<double>();
            } else {
                runQueue<Student>();
            }
        }

    } while (true);

    return 0;
}