#pragma once
#include <string>
#include "ISerializable.hpp"

class Human : public ISerializable {
private:
    std::string idCard;     // CMND/CCCD
    std::string fullName;   // Họ tên
    int birthYear{};        // Năm sinh
    int age{};              // Tuổi
    std::string job;        // Nghề nghiệp

public:
    Human() = default;
    Human(std::string id, std::string name, int birthYear, int age, std::string job);

    const std::string& getIdCard() const;
    const std::string& getFullName() const;
    int getBirthYear() const;
    int getAge() const;
    const std::string& getJob() const;

    void input(std::istream& in) override;
    void output(std::ostream& out) const override;
};