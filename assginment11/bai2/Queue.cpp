#include "Queue.hpp"
#include <iostream>
using namespace std;

Queue::Queue() {
    front = 0;
    rear = -1;
    count = 0;
}

bool Queue::isEmpty() const {
    return count == 0;
}

bool Queue::isFull() const {
    return count == MAX;
}

bool Queue::enqueue(const Student& student) {
    if (isFull()) {
        cout << "Queue is full. Cannot add more students.\n";
        return false;
    }

    rear = (rear + 1) % MAX;
    data[rear] = student;
    count++;
    return true;
}

bool Queue::dequeue(Student& student) {
    if (isEmpty()) {
        cout << "Queue is empty. Cannot remove student.\n";
        return false;
    }

    student = data[front];
    front = (front + 1) % MAX;
    count--;
    return true;
}

bool Queue::peek(Student& student) const {
    if (isEmpty()) {
        cout << "Queue is empty.\n";
        return false;
    }

    student = data[front];
    return true;
}

void Queue::display() const {
    if (isEmpty()) {
        cout << "Queue is empty.\n";
        return;
    }

    cout << "Current students in queue:\n";
    int i = front;

    for (int c = 0; c < count; c++) {
        data[i].output();
        i = (i + 1) % MAX;
    }
}