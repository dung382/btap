#include "Hotel.hpp"
#include <iostream>
#include "../InputUtils.hpp"

void Hotel::input(std::istream& in) {
    int n = readInt("Enter number of renters: ", 0);

    rentals.clear();
    rentals.reserve(static_cast<size_t>(n));

    for (int i = 0; i < n; ++i) {
        std::cout << "\n=== Input renter #" << (i + 1) << " ===\n";
        Rental r;
        r.input(in);
        rentals.push_back(r);
    }
}

void Hotel::displayAll(std::ostream& out) const {
    out << "\n===== CURRENT RENTERS =====\n";
    if (rentals.empty()) {
        out << "No renters available.\n";
        return;
    }

    for (int i = 0; i < (int)rentals.size(); ++i) {
        out << "  [" << (i + 1) << "] ";
        rentals[i].output(out);
        out << "\n";
    }
}

void Hotel::searchByName(const std::string& keyword, std::ostream& out) const {
    out << "\n===== SEARCH RENTERS BY NAME KEYWORD: \"" << keyword << "\" =====\n";
    bool found = false;

    for (const auto& r : rentals) {
        if (r.matchNameKeyword(keyword)) {
            r.output(out);
            out << "\n";
            found = true;
        }
    }

    if (!found) out << "No matching renter found.\n";
}

void Hotel::checkoutByName(const std::string& keyword, std::ostream& out) const {
    out << "\n===== CHECKOUT BY NAME KEYWORD: \"" << keyword << "\" =====\n";
    bool found = false;
    double total = 0;

    for (const auto& r : rentals) {
        if (r.matchNameKeyword(keyword)) {
            r.output(out);
            out << "\n";
            total += r.calcBill();
            found = true;
        }
    }

    if (!found) {
        out << "No matching renter found.\n";
        return;
    }

    out << "Total payment: " << total << "\n";
}