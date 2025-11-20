#include <iostream>
using namespace std;
int main() {
    int N;
    cout << "Nhap n : ";
    cin >> N;

    long long f1 = 0;
    long long f2 = 1;
    cout << f1 << "\t" << f2 << "\t";

    if ( N < 0 || N > 100) {
        cout << "N phai nam trong khoang 0 < n < 100!";
        return 0;
    }

    if (N == 0) {
        cout << "so fib o vi tri " << N << " la " << f1;
    } else if (N == 1) {
        cout << "so fib o vi tri " << N << " la " << f2;
    } else {
        for (int i = 3; i <= N; i++) {
            long long fn = f1 + f2;
            f1 = f2;
            f2 = fn;
            cout << "so fib o vi tri " << N << " la " << fn;
        }
    }
    return 0;
}