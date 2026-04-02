#pragma once

#include <string>

class InputHelperbai3 {
public:
    static int inputInt(const std::string& message);
    static double inputDouble(const std::string& message);
    static int inputIntInRange(const std::string& message, int min, int max);
};
