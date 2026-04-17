#include <iostream>
#include "Math_utils/MathUtils.hpp"

using namespace std;

int main() {
    double a = 10, b = 5;

    cout << "a + b = " << add(a, b) << endl;
    cout << "a - b = " << sub(a, b) << endl;
    cout << "a * b = " << mul(a, b) << endl;
    cout << "a / b = " << divi(a, b) << endl;

    return 0;
}
// cach chay static library
// g++ -c Math_utils/MathUtils.cpp -o MathUtils.o
// ar rcs libmath.a MathUtils.o
// g++ Main.cpp -L. -lmath -o bai3
// ./bai3


// cach chay dynamic library
// g++ -fPIC -shared Math_utils/MathUtils.cpp -o libmath.so
// g++ Main.cpp -L. -lmath -o bai3
// LD_LIBRARY_PATH=. ./bai3