#include "Human.hpp"
#include <limits>
#include <iostream>

Human::Human(std::string id, std::string name, int by, int a, std::string j)
    : idCard(std::move(id)), fullName(std::move(name)), birthYear(by), age(a), job(std::move(j)) {}

const std::string& Human::getIdCard() const { return idCard; }
const std::string& Human::getFullName() const { return fullName; }
int Human::getBirthYear() const { return birthYear; }
int Human::getAge() const { return age; }
const std::string& Human::getJob() const { return job; }

void Human::input(std::istream& in) {
    // Xóa newline còn dư trước khi getline
    in.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    std::cout << "  ID card (CMND/CCCD): ";
    std::getline(in, idCard);

    std::cout << "  Full name: ";
    std::getline(in, fullName);

    std::cout << "  Birth year: ";
    in >> birthYear;

    std::cout << "  Age: ";
    in >> age;

    in.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cout << "  Job: ";
    std::getline(in, job);
}

void Human::output(std::ostream& out) const {
    out << "ID: " << idCard
        << " | Name: " << fullName
        << " | BirthYear: " << birthYear
        << " | Age: " << age
        << " | Job: " << job;
}