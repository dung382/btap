#include <cmath>
#include <iostream>
using namespace std;
void TimNghiem(double a, double b, double c) {
  double delta = b * b - 4 * a * c;
  if (delta > 0) {
    double x1 = ((-b + sqrt(delta)) / 2 * a);
    double x2 = ((-b - sqrt(delta)) / 2 * a);
    cout << "nghiem thu 1 : " << x1 << "nghiem thu 2 : " << x2 << endl;
  } else if (delta == 0) {
    double x1 = ((-b) / 2 * a);
    cout << "phuong trinh co nghiem kep la : " << x1 << endl;
  } else {
    cout << "phuong trinh vo nghiem !" << endl;
  }
}
int main() {
  double a, b, c;
  while (true) {
    cout << "nhap a : ";
    cin >> a;
    cout << "nhap b : ";
    cin >> b;
    cout << "nhap c : ";
    cin >> c;

    if (a == 0 && b == 0 && c == 0) {
      break;
    }

    TimNghiem(a, b, c);
  }
}