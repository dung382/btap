#include "Household.hpp"
#include "../InputUtils.hpp"
#include <iostream>

int Household::getMemberCount() const { return memberCount; }
int Household::getHouseNumber() const { return houseNumber; }
const std::vector<Human>& Household::getMembers() const { return members; }

bool Household::hasNameKeyword(const std::string& keyword) const {
    // Tìm xem trong hộ có ai có tên chứa keyword không
    for (const auto& h : members) {
        if (h.getFullName().find(keyword) != std::string::npos) return true;
    }
    return false;
}

void Household::input(std::istream& in) {
    houseNumber = readInt("House number: ", 0);

    memberCount = readInt("Number of members: ", 0);
    if (memberCount < 0) memberCount = 0;

    members.clear();
    members.reserve(static_cast<size_t>(memberCount));

    for (int i = 0; i < memberCount; ++i) {
        std::cout << "Enter member #" << (i + 1) << ":\n";
        Human h;
        h.input(in);
        members.push_back(h);
    }
}

void Household::output(std::ostream& out) const {
    out << "House number: " << houseNumber
        << " | Members: " << memberCount << "\n";

    for (int i = 0; i < (int)members.size(); ++i) {
        out << "  - [" << (i + 1) << "] ";
        members[i].output(out);
        out << "\n";
    }
}