#include <iostream>
#include <string>
using namespace std;

int main() {
    string s1;
    cout << "nhap chuoi 1 : ";
    cin >> s1;
    string s2;
    cout << "nhap chuoi 2 : ";
    cin >> s2;
    if (s1 > s2) {
        cout << "chuoi dai hon la : " << s1 << endl;
    } else if(s2 < s1) {
        cout << "chuoi dai hon la : " << s2 << endl;
    } else {
        cout << "equal length" << endl;
    }
    return 0;
}