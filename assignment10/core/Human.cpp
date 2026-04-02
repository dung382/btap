#include "Human.hpp"
#include <limits>
#include <iostream>
#include "../InputUtils.hpp"

Human::Human(std::string id, std::string name, int by, int a, std::string j)
    : idCard(std::move(id)), fullName(std::move(name)), birthYear(by), age(a), job(std::move(j)) {}

const std::string& Human::getIdCard() const { return idCard; }
const std::string& Human::getFullName() const { return fullName; }
int Human::getBirthYear() const { return birthYear; }
int Human::getAge() const { return age; }
const std::string& Human::getJob() const { return job; }

void Human::input(std::istream& in) {
    idCard   = readLine(in, "  ID card (CMND/CCCD): ");
    fullName = readLine(in, "  Full name: ");

    birthYear = readInt(in, "  Birth year: ", 1900, 2100);
    age       = readInt(in, "  Age: ", 0, 150);

    job = readLine(in, "  Job: ");
}

void Human::output(std::ostream& out) const {
    out << "ID: " << idCard
        << " | Name: " << fullName
        << " | BirthYear: " << birthYear
        << " | Age: " << age
        << " | Job: " << job;
}