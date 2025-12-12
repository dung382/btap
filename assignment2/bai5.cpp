#include <iostream>
using namespace std;
void GiaiToan(float a, float b) {
    if (a == 0) {
        if (b == 0) {
            cout << "Phuong trinh vo so nghiem !" << endl;
        } else {
            cout << "Phuong trinh vo nghiem !" << endl;
        }
    } else {
        float x = -b / a;
        cout << "phuong trinh co nghiem la : " << x << endl;
    }
}
int main() {
    float a;
    cout << "nhap a : ";
    cin >> a;
    float b;
    cout << "nhap b : ";
    cin >> b;

    GiaiToan(a, b);
    return 0;
}