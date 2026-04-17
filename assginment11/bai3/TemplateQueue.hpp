#pragma once

template <typename T>
class TemplateQueue {
private:
    static const int MAX = 20;
    T data[MAX];
    int front;
    int rear;
    int count;

public:
    TemplateQueue() : front(0), rear(-1), count(0) {
    }

    bool isFull() const {
        return count == MAX;
    }

    bool isEmpty() const {
        return count == 0;
    }

    bool enqueue(const T& value) {
        if (isFull()) {
            return false;
        }

        rear = (rear + 1) % MAX;
        data[rear] = value;
        ++count;
        return true;
    }

    bool dequeue(T& value) {
        if (isEmpty()) {
            return false;
        }

        value = data[front];
        front = (front + 1) % MAX;
        --count;
        return true;
    }

    bool peek(T& value) const {
        if (isEmpty()) {
            return false;
        }

        value = data[front];
        return true;
    }
};