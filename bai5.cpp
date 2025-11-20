#include <iostream>
using namespace std;
void GiaiToan(int a, int b) {
    int x = -b / a;
    if (a == 0) {
        if (b == 0) {
            cout << "Phuong trinh vo so nghiem !" << endl;
        } else {
            cout << "Phuong trinh vi nghiem !" << endl;
        }
    } else {
        cout << "phuong trinh co nghiem la : " << x << endl;
    }
}
int main() {
    int a;
    int b;
    GiaiToan(a, b);
    return 0;
}