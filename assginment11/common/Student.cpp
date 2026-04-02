#include "Student.hpp"
#include "InputHelper.hpp"

Student::Student() {
    id = "";
    name = "";
}

Student::Student(string id, string name) {
    this->id = id;
    this->name = name;
}

void Student::input() {
    id = InputHelper::inputNonEmptyString("Enter student ID: ");
    name = InputHelper::inputNonEmptyString("Enter student name: ");
}

void Student::output() const {
    cout << "ID: " << id << " | Name: " << name << endl;
}