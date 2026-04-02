#include <iostream>
#include "Queue.hpp"
#include "../common/InputHelper.hpp"
using namespace std;

int main() {
    Queue queue;
    Student student;
    int addCount1, removeCount, addCount2;

    cout << "===== QUEUE MANAGEMENT =====\n";

    // 1. Them lan dau
    addCount1 = InputHelper::inputIntInRange("Enter number of students to add first time: ", 1, 100);

    cout << "\n--- ADD FIRST BATCH ---\n";
    for (int i = 0; i < addCount1; i++) {
        if (queue.isFull()) {
            cout << "Queue is full. Cannot add more students.\n";
            break;
        }

        cout << "\nStudent " << i + 1 << ":\n";
        student.input();
        queue.enqueue(student);
    }

    // 2. in 
    cout << "\nQueue before removing:\n";
    queue.display();

    // 3. xoa tung phan tu, check empty truoc khi xoa
    removeCount = InputHelper::inputIntInRange("\nEnter number of students to remove: ", 1, 100);

    cout << "\n--- REMOVE STUDENTS FROM QUEUE ---\n";
    for (int i = 0; i < removeCount; i++) {
        if (queue.isEmpty()) {
            cout << "Queue is empty. Cannot remove more students.\n";
            break;
        }

        if (queue.dequeue(student)) {
            cout << "Removed: ";
            student.output();
        }
    }

    cout << "\nQueue after removing:\n";
    queue.display();

    // 4. them lan 2
    addCount2 = InputHelper::inputIntInRange("\nEnter number of students to add second time: ", 1, 100);

    cout << "\n--- ADD SECOND BATCH ---\n";
    for (int i = 0; i < addCount2; i++) {
        if (queue.isFull()) {
            cout << "Queue is full. Cannot add more students.\n";
            break;
        }

        cout << "\nNew student " << i + 1 << ":\n";
        student.input();
        queue.enqueue(student);
    }

    cout << "\nFinal queue:\n";
    queue.display();

    return 0;
}