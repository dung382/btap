#include <iostream>
#include <string>
using namespace std;

int main() {
    string firstName;
    string lastName;
    unsigned short age;
    string gender;
    string personalID;
    unsigned int employeeNumber;

    cout << "Nhap ho: ";
    cin >> firstName;

    cout << "Nhap ten: ";
    cin >> lastName;

    cout << "Nhap tuoi: ";
    cin >> age;

    cout << "nhap gioi tinh (nam/nu): ";
    cin >> gender;

    cout << "ID: ";
    cin >> personalID;

    cout << "ma nhan vien(doc nhat): ";
    cin >> employeeNumber;

    cout << "\n===== EMPLOYEE INFORMATION =====" << endl;
    cout << "First name: " << firstName << endl;
    cout << "Last name: " << lastName << endl;
    cout << "Age: " << age << endl;
    cout << "Gender: " << gender << endl;
    cout << "Personal ID: " << personalID << endl;
    cout << "Unique Employee number: " << employeeNumber << endl;

    return 0;
}