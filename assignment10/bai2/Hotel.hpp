#pragma once
#include <vector>
#include <string>
#include "Rental.hpp"

class Hotel {
private:
    std::vector<Rental> rentals;

public:
    void input(std::istream& in);
    void displayAll(std::ostream& out) const;

    void searchByName(const std::string& keyword, std::ostream& out) const;

    // Thanh toan: nhập keyword tên, hiện các match + tổng tiền của các match
    void checkoutByName(const std::string& keyword, std::ostream& out) const;
};