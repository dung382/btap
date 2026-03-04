#include "Rental.hpp"
#include <iostream>
#include <limits>
#include "../InputUtils.hpp"

const Human& Rental::getPerson() const { return person; }
int Rental::getDays() const { return days; }
double Rental::getPricePerDay() const { return pricePerDay; }
const std::string& Rental::getRoomType() const { return roomType; }

double Rental::calcBill() const {
    // Nếu input âm thì trả về 0 để an toàn
    if (days < 0 || pricePerDay < 0) return 0;
    return days * pricePerDay;
}

bool Rental::matchNameKeyword(const std::string& keyword) const {
    return person.getFullName().find(keyword) != std::string::npos;
}

void Rental::input(std::istream& in) {
    std::cout << "Enter renter information:\n";
    person.input(in);

    days      = readInt(in, "Number of days: ", 1);
    roomType  = readLine(in, "Room type: ");
    pricePerDay = readDouble(in, "Price per day: ", 0);
}

void Rental::output(std::ostream& out) const {
    person.output(out);
    out << " | Room type: " << roomType
        << " | Days: " << days
        << " | Price/day: " << pricePerDay
        << " | Total: " << calcBill();
}