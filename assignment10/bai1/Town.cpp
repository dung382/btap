#include "Town.hpp"
#include <iostream>

void Town::input(std::istream& in) {
    int n;
    std::cout << "Enter number of households: ";
    in >> n;
    if (n < 0) n = 0;

    households.clear();
    households.reserve(static_cast<size_t>(n));

    for (int i = 0; i < n; ++i) {
        std::cout << "\n=== Input household #" << (i + 1) << " ===\n";
        Household h;
        h.input(in);
        households.push_back(h);
    }
}

void Town::displayAll(std::ostream& out) const {
    out << "\n===== HOUSEHOLD LIST =====\n";
    if (households.empty()) {
        out << "No households available.\n";
        return;
    }

    for (int i = 0; i < (int)households.size(); ++i) {
        out << "\n-- Household #" << (i + 1) << " --\n";
        households[i].output(out);
    }
}

void Town::searchByName(const std::string& keyword, std::ostream& out) const {
    out << "\n===== SEARCH BY NAME KEYWORD: \"" << keyword << "\" =====\n";
    bool found = false;

    for (const auto& hh : households) {
        if (hh.hasNameKeyword(keyword)) {
            hh.output(out);
            out << "\n";
            found = true;
        }
    }

    if (!found) out << "No matching household found.\n";
}

void Town::searchByHouseNumber(int houseNumber, std::ostream& out) const {
    out << "\n===== SEARCH BY HOUSE NUMBER: " << houseNumber << " =====\n";
    bool found = false;

    for (const auto& hh : households) {
        if (hh.getHouseNumber() == houseNumber) {
            hh.output(out);
            out << "\n";
            found = true;
        }
    }

    if (!found) out << "No matching household found.\n";
}