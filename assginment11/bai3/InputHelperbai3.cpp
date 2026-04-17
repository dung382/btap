#include "InputHelperbai3.hpp"
#include <iostream>
#include <limits>

int InputHelperbai3::inputInt(const std::string& message) {
    int value;
    while (true) {
        std::cout << message;
        std::cin >> value;

        if (!std::cin.fail()) {
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            return value;
        }

        std::cout << "Error: Please enter a valid integer.\n";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
}

double InputHelperbai3::inputDouble(const std::string& message) {
    double value;
    while (true) {
        std::cout << message;
        std::cin >> value;

        if (!std::cin.fail()) {
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            return value;
        }

        std::cout << "Error: Please enter a valid double number.\n";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
}

int InputHelperbai3::inputIntInRange(const std::string& message, int min, int max) {
    int value;
    while (true) {
        value = inputInt(message);
        if (value >= min && value <= max) {
            return value;
        }

        std::cout << "Error: Value must be in range [" << min << ", " << max << "].\n";
    }
}