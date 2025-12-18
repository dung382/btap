#include <iomanip>
#include <iostream>
#include <string>

using namespace std;

// --- 1. Các hàm tính toán cơ bản ---
double add(double a, double b) { return a + b; }
double sub(double a, double b) { return a - b; }
double multi(double a, double b) { return a * b; }
double divi(double a, double b) { return (b != 0) ? (a / b) : 0; }
double mod(double a, double b) { return (int)a % (int)b; }

// --- 2. Định nghĩa kiểu con trỏ hàm ---
typedef double (*Operation)(double, double);

// --- 3. Hàm thực thi (Hàm này nhận con trỏ hàm làm tham số) ---
void executeAndPrint(string label, Operation func, double a, double b) {
  cout << label << "(A, B) = ";

  if (label == "Div") {
    // In chính xác 7 chữ số thập phân cho phép chia
    cout << fixed << setprecision(7) << func(a, b) << endl;
    cout << defaultfloat;
  } else if (label == "Mod") {
    cout << (int)func(a, b) << endl;
  } else {
    cout << func(a, b) << endl;
  }
}

int main() {
  double A, B;
  cout << "Nhap A = ";
  cin >> A;
  cout << "Nhap B = ";
  cin >> B;

  cout << "\n--- Ket qua ---" << endl;

  // Truyền con trỏ hàm (add, sub, multi...) vào hàm thực thi
  executeAndPrint("Add", add, A, B);
  executeAndPrint("Sub", sub, A, B);
  executeAndPrint("Multi", multi, A, B);
  executeAndPrint("Div", divi, A, B);
  executeAndPrint("Mod", mod, A, B);

  return 0;
}