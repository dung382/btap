#include <fstream>
#include <iostream>
using namespace std;

int main() {
  int a, b;
  ifstream inputFile("btap3.txt");
  if (!inputFile.is_open()) {
    cout << "file khong ton tai !" << endl;
  }
  if (inputFile >> a >> b) {
    int sum = a + b;
    int diff = a - b;
    cout << " a = " << a << endl;
    cout << "b = " << b << endl;
    cout << "Sum(a, b) = " << sum << endl;
    cout << "Diff(a, b) = " << diff << endl;
  }

  return 0;
}