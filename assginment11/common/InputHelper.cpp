#include "InputHelper.hpp"
#include <iostream>
#include <limits>

int InputHelper::inputInt(const std::string& message) {
    int value;
    while (true) {
        std::cout << message;
        std::cin >> value;

        if (!std::cin.fail()) {
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            return value;
        }

        std::cout << "Loi: Vui long nhap so nguyen hop le.\n";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
}

int InputHelper::inputIntInRange(const std::string& message, int min, int max) {
    int value;
    while (true) {
        value = inputInt(message);
        if (value >= min && value <= max) {
            return value;
        }
        std::cout << "Loi: Gia tri phai nam trong khoang [" << min << ", " << max << "].\n";
    }
}

std::string InputHelper::inputNonEmptyString(const std::string& message) {
    std::string value;
    while (true) {
        std::cout << message;
        std::getline(std::cin, value);

        if (!value.empty()) {
            return value;
        }

        std::cout << "Loi: Khong duoc de trong.\n";
    }
}