#include <iostream>
#include <string>
#include <iomanip> 
using namespace std;

int main() {
    int myNum = 1;                 
    int myNum1 = 10001;                    
    int myNum2 = 100000001;                 
    long long myNum3 = 10000000000001;    
    long long myNum4 = -10000000000001;

    float myDoubleNum = 1.001;            
    string myDoubleNum1 = "100000000000001.100001";
    double myDoubleNum2 = -1000000001.100001;

    char myLetter = 'A';
    char myLetter1 = 'c';                   
    string myText = "Hello World";
    bool myBool = false;

    cout << myNum << endl;
    cout << myNum1 << endl;
    cout << myNum2 << endl;
    cout << myNum3 << endl;
    cout << myNum4 << endl;
    cout << myDoubleNum << endl;
    cout << myDoubleNum1 << endl;
    cout << myDoubleNum2 << endl;
    cout << myLetter << endl;
    cout << myLetter1 << endl;
    cout << myText << endl;
    cout << boolalpha << myBool << endl;

    return 0;
}
