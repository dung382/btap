#include <iostream>
using namespace std;
void Change(int A, int B) {
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
    return 0;
}