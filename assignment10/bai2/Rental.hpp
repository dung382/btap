#pragma once
#include <string>
#include "../core/ISerializable.hpp"
#include "../core/Human.hpp"

class Rental : public ISerializable {
private:
    Human person;
    int days{};                 // Số ngày trọ
    std::string roomType;       // Loại phòng
    double pricePerDay{};       // Giá phòng / ngày

public:
    const Human& getPerson() const;
    int getDays() const;
    double getPricePerDay() const;
    const std::string& getRoomType() const;

    double calcBill() const;    // Tính tiền

    bool matchNameKeyword(const std::string& keyword) const;

    void input(std::istream& in) override;
    void output(std::ostream& out) const override;
};