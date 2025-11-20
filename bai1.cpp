#include <iostream>
using namespace std;
int main() {
    int soBiChia;
    cout << "nhap so bi chia : ";
    cin >> soBiChia;
    int soChia;
    cout << "nhap so chia : ";
    cin >> soChia;
    int Thuong = soBiChia / soChia;
    int Du = soBiChia % soChia;
    cout << "ket qua thuong = " << Thuong << "phan du con lai : " << Du << endl;
    return 0;
}