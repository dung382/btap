#ifndef CUSTOMER_HPP
#define CUSTOMER_HPP

using namespace std;

#include <iostream>
#include <string>

class Customer {
private:
    string fullName; 
    string houseNumber;
    string meterID; 

public:
    Customer(string name = "", string house = "", string id = "");
    void inputCustomerDetails(); 
    void displayCustomerInfo() const; 

    friend class Receipt; 
};

#endif