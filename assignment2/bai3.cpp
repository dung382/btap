#include <iostream>
using namespace std;
void Check(int N) {
    if (N % 2 == 0) {
        cout << "N la so chan !";
    } else {
        cout << "N la so le !";
    }
}
int main() {
    int N;
    cout << "Nhap N" << endl;
    cin >> N;
    Check(N);
    return 0;
}