#include "Receipt.hpp"
#include <iostream>

using namespace std;

int Receipt::totalReceiptsProcessed = 0;

Receipt::Receipt() : oldMeterIndex(0), newMeterIndex(0) {
    totalReceiptsProcessed++;
}

void Receipt::inputUsageData() {
    this->household.inputCustomerDetails();
    cout << "Enter Old Meter Index: "; cin >> this->oldMeterIndex;
    do {
        cout << "Enter new electricity reading (must be >= " <<this->oldMeterIndex<< "): ";
        cin >> this->newMeterIndex;

        if (this->newMeterIndex < this->oldMeterIndex) {
            cout << "[Error] Invalid input! New reading cannot be less than old reading. Please try again." << endl;
        }
    } while (this->newMeterIndex < this->oldMeterIndex);
    cin.ignore();
}

long Receipt::calculateTotalBill() const {
    int consumption = this->newMeterIndex - this->oldMeterIndex;
    
    if (consumption < LOW_CONSUMPTION_LIMIT) {
        return (long)consumption * PRICE_LEVEL_1; 
    } 
    else if (consumption < HIGH_CONSUMPTION_LIMIT) {
        return (long)consumption * PRICE_LEVEL_2; 
    } 
    else {
        return (long)consumption * PRICE_LEVEL_3;
    }
}

void Receipt::printReceiptDetails() const {
    this->household.displayCustomerInfo();
    cout << " | Consumption: " << (this->newMeterIndex - this->oldMeterIndex)
              << " | Amount: " << this->calculateTotalBill() << " VND" << endl;
}

int Receipt::getGlobalReceiptCount() {
    return totalReceiptsProcessed;
}