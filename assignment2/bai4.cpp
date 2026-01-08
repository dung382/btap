#include <iostream>
using namespace std;
void Change(int &A, int &B) {
    int temp = A;
    A = B;
    B = temp;
}
int main() {
    int A;
    cout << "Nhap A : " << endl;
    cin >> A;
    int B;
    cout << "Nhap B : " << endl;
    cin >> B;
    Change(A, B);
    cout << "gia tri cua a sau khi doi " << A << " gia tri cua b sau khi doi " << B << endl;
    return 0;
}