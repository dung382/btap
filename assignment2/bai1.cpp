#include <iostream>
using namespace std;
int main() {
    int soBiChia;
    cout << "nhap so bi chia : ";
    cin >> soBiChia;
    int soChia;
    cout << "nhap so chia : ";
    cin >> soChia;
    if(soChia == 0) {
        cout << "so chia phai khac 0 !" << endl;
    } else {
        int Thuong = soBiChia / soChia;
        int Du = soBiChia % soChia;
        cout << "ket qua thuong = " << Thuong << "phan du con lai : " << Du << endl;
    }
    return 0;
}