#pragma once

template <typename T>
class TemplateStack {
private:
    static const int MAX = 20;
    T data[MAX];
    int top;

public:
    TemplateStack() : top(-1) {
    }

    bool isFull() const {
        return top == MAX - 1;
    }

    bool isEmpty() const {
        return top == -1;
    }

    bool push(const T& value) {
        if (isFull()) {
            return false;
        }
        data[++top] = value;
        return true;
    }

    bool pop(T& value) {
        if (isEmpty()) {
            return false;
        }
        value = data[top--];
        return true;
    }

    bool peek(T& value) const {
        if (isEmpty()) {
            return false;
        }
        value = data[top];
        return true;
    }
};