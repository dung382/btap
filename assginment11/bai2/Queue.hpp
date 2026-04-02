#pragma once
#include "../common/Student.hpp"

class Queue {
private:
    static const int MAX = 10;
    Student data[MAX];
    int front;
    int rear;
    int count;

public:
    Queue();

    bool isEmpty() const;
    bool isFull() const;

    bool enqueue(const Student& student);
    bool dequeue(Student& student);
    bool peek(Student& student) const;

    void display() const;
};