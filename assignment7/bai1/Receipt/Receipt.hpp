#ifndef RECEIPT_HPP
#define RECEIPT_HPP

#include "../Customer/Customer.hpp"

using namespace std;

class Receipt {
private:
    Customer household;
    int oldMeterIndex; 
    int newMeterIndex; 
    static int totalReceiptsProcessed; 

    
    static const int LOW_CONSUMPTION_LIMIT = 50;  
    static const int HIGH_CONSUMPTION_LIMIT = 100; 
    
    static const int PRICE_LEVEL_1 = 1250; 
    static const int PRICE_LEVEL_2 = 1500; 
    static const int PRICE_LEVEL_3 = 2000;

public:
    Receipt();
    void inputUsageData();
    long calculateTotalBill() const;
    void printReceiptDetails() const;

    static int getGlobalReceiptCount(); 
};

#endif