#pragma once
#include <vector>
#include <string>
#include "Household.hpp"

class Town {
private:
    std::vector<Household> households;

public:
    void input(std::istream& in);
    void displayAll(std::ostream& out) const;

    // Tìm theo keyword họ tên (match chứa keyword)
    void searchByName(const std::string& keyword, std::ostream& out) const;

    // Tìm theo số nhà
    void searchByHouseNumber(int houseNumber, std::ostream& out) const;
};