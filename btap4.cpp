#include <fstream>
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

  ifstream inputFile("btap4.txt");
  if (!inputFile.is_open()) {
    cout << "khong the mo file !";
  }

  if (inputFile >> firstName >> lastName >> age >> gender >> personalID >> employeeNumber) {
        cout << "\n===== EMPLOYEE INFORMATION =====" << endl;
        cout << "First name: " << firstName << endl;
        cout << "Last name: " << lastName << endl;
        cout << "Age: " << age << endl;
        cout << "Gender: " << gender << endl;
        cout << "Personal ID: " << personalID << endl;
        cout << "Unique Employee number: " << employeeNumber << endl;
  }

  return 0;
}