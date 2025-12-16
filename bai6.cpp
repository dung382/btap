#include <iostream>
using namespace std;
int main() {
    long long f1 = 0;
    long long f2 = 1;
    cout << f1 << "\t" << f2 << "\t";
    for (int i = 3; i <= 100; i++) {
        long long fn = f1 + f2;
        cout << fn << "\t";
        f1 = f2;
        f2 = fn;
    }
    return 0;
}