#include <iomanip>
#include <iostream>
using namespace std;

void add(int *a, int *b) { cout << "Add(A, B) = " << (*a + *b) << endl; }

void sub(int *a, int *b) { cout << "Sub(A, B) = " << (*a - *b) << endl; }

void multi(int *a, int *b) { cout << "Multi(A, B) = " << (*a * *b) << endl; }

void divide(int *a, int *b) {
  cout << fixed << setprecision(7);
  cout << "Div(A, B) = " << ((double)*a / *b) << endl;
}

void mod(int *a, int *b) { cout << "Mod(A, B) = " << (*a % *b) << endl; }

int main() {
  int A, B;
  cout << "Nhap A: ";
  cin >> A;
  cout << "Nhap B: ";
  cin >> B;

  add(&A, &B);
  sub(&A, &B);
  
  multi(&A, &B);
  divide(&A, &B);
  mod(&A, &B);
  return 0;
}
