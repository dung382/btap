#include <iostream>
using namespace std;
int GDC(int a, int b) {
    while (b != 0) {
        int r = a % b;
        a = b;
        b = r;
    }
    return a;
}
int LCM(int a, int b) { return ((a * b) / GDC(a, b)); }
int main() {
    int a;
    int b;
    cout << "nhap a : ";
    cin >> a;
    while (true) {
        cout << "nhap a : ";
        cin >> a;
        if (a < 1) {
            cout << "a khong duoc nho hon 1 !";
        } else {
            break;
        }
    }
    cout << "nhap b : ";
    cin >> b;
    cout << "uoc chung lon nhat la " << GDC(a, b) << endl;
    cout << "boi chung nho nhat : " << LCM(a, b) << endl;
    return 0;
}