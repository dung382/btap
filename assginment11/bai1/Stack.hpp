#pragma once
#include "../common/Student.hpp"

class Stack {
private:
    static const int MAX = 10;
    Student data[MAX];
    int top;

public:
    Stack();

    bool isEmpty() const;
    bool isFull() const;

    bool push(const Student& student);
    bool pop(Student& student);
    bool peek(Student& student) const;

    void display() const;
};