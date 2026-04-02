#include "Customer.hpp"

using namespace std;
    
Customer::Customer(string name, string house, string id) {
    this->fullName = name;
    this->houseNumber = house;
    this->meterID = id;
}

void Customer::inputCustomerDetails() {
    cout << "[LOG] Enter Customer Details" << endl;
    cout << "Full Name: "; getline(cin, this->fullName);
    cout << "House Number: "; getline(cin, this->houseNumber);
    cout << "Meter ID: "; getline(cin, this->meterID);
}

void Customer::displayCustomerInfo() const {
    cout << "Owner: " << this->fullName 
            << " | House: " << this->houseNumber 
            << " | Meter ID: " << this->meterID;
}