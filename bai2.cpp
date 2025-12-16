#include <iostream>

using namespace std;

bool Check(int N) {
    if (N <= 1) return false;
    for (int i = 0; i * i < N; i++) {
        if (N % i == 0) {
            return false;
        } else {
            return true;
        }
    }
}
int main() {
    int N;
    cout << "Nhap n : " << endl;
    cin >> N;
    if (N > 1 && N < 10000) {
        cout << "N khong thoa man dieu kien !" << endl;
        return 0;
    }

    if (Check(N)) {
        cout << N << " la so nguyen to" << endl;
    }
    return 0;
}