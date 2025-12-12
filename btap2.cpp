#include <iostream>
using namespace std;

int main() {
    int a = 5;
    int b = 10;

    cout << "Before: a = " << a << " b = " << b << endl;

    int temp = a;
        a = b;
        b = temp;

    cout << "After: a = " << a << " b = " << b << endl;

    return 0;
}