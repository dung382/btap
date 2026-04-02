#pragma once
#include <string>

class InputHelper {
public:
    static int inputInt(const std::string& message);
    static int inputIntInRange(const std::string& message, int min, int max);
    static std::string inputNonEmptyString(const std::string& message);
};