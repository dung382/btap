#include <cmath>
#include <iostream>
#include <limits>

using namespace std;

bool Check(int N) {
    if (N <= 1) return false;
    for (int i = 2; i * i <= N; i++) {
        if (N % i == 0) {
            return false;
        }
    }
    return true;
}
int main() {
    int N;
    char check;
    while (true) {
        cout << "Nhap n : " << endl;
        cin >> N;
        while (true) {
            if (cin.fail() || N <= 1 || N >= 10000) {
                cout << "Loi: Ban phai nhap mot so nguyen nam trong khoang (1, 10000)!" << endl;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            } else {
                break;
            }
        }
        if (Check(N)) {
            cout << N << " la so nguyen to" << endl;
        } else {
            cout << "N khong phai so nguyen to !" << endl;
        }
        cout << "co muon tiep tuc nhap so 0(y/n) :";
        if (check == 'n') {
            return 0;
        }
    }
}