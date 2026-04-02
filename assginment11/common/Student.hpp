#pragma once
#include <iostream>
#include <string>
using namespace std;

class Student {
private:
    string id;
    string name;

public:
    Student();
    Student(string id, string name);

    void input();
    void output() const;
};