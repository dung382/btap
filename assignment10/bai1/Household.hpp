#pragma once
#include <vector>
#include "../core/ISerializable.hpp"
#include "../core/Human.hpp"

class Household : public ISerializable {
private:
    int memberCount{};              // Số thành viên
    int houseNumber{};              // Số nhà
    std::vector<Human> members;     // Danh sách người

public:
    int getMemberCount() const;
    int getHouseNumber() const;
    const std::vector<Human>& getMembers() const;

    bool hasNameKeyword(const std::string& keyword) const;

    void input(std::istream& in) override;
    void output(std::ostream& out) const override;
};