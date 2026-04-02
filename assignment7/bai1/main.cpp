#include <iostream>
#include "Receipt.hpp"

using namespace std;

int main() {
    int numberOfHouseholds;
    cout << "=== ELECTRICITY BILLING SYSTEM ===" << endl;
    cout << "Enter number of households to process: ";
    cin >> numberOfHouseholds;
    cin.ignore();

    Receipt* receiptList = new Receipt[numberOfHouseholds];

    for (int i = 0; i < numberOfHouseholds; i++) {
        cout << "\n[Input] Household " << i + 1 << ":" << endl;
        receiptList[i].inputUsageData();
    }

    cout << "\n=== FINAL RECEIPTS REPORT ===" << endl;
    for (int i = 0; i < numberOfHouseholds; i++) {
        receiptList[i].printReceiptDetails();
    }

    cout << "\n[Summary] Total records handled: " << Receipt::getGlobalReceiptCount() << endl;

    delete[] receiptList;

    return 0;
}