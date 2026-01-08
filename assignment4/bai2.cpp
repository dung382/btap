#include <iostream>
#include <string> 
using namespace std;

int main() {
    string s1;
    cout << "Nhap chuoi 1: ";
    getline(cin, s1); 

    string s2;
    cout << "Nhap chuoi 2: ";
    getline(cin, s2);

    if (s1.length() > s2.length()) {
        cout << "Chuoi dai hon la: " << s1 << endl;
        cout << "(Do dai: " << s1.length() << ")" << endl;
    } 
    else if (s2.length() > s1.length()) {
        cout << "Chuoi dai hon la: " << s2 << endl;
        cout << "(Do dai: " << s2.length() << ")" << endl;
    } 
    else {
        cout << "Hai chuoi bang nhau (Equal length)" << endl;
    }
    
    return 0;
}