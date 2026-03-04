#pragma once
#include <iostream>
#include <limits>
#include <string>

// ===== Core functions that work with ANY istream =====
inline int readInt(std::istream& in,
                   const std::string& prompt,
                   int minVal = std::numeric_limits<int>::min(),
                   int maxVal = std::numeric_limits<int>::max())
{
    while (true) {
        std::cout << prompt;

        int value;
        if (!(in >> value)) {
            std::cout << "Invalid input. Please enter a valid integer.\n";
            in.clear();
            in.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue;
        }

        // consume the rest of the line (including '\n')
        in.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        if (value < minVal || value > maxVal) {
            std::cout << "Value must be in range [" << minVal << ", " << maxVal << "].\n";
            continue;
        }

        return value;
    }
}

inline double readDouble(std::istream& in,
                         const std::string& prompt,
                         double minVal = -std::numeric_limits<double>::infinity(),
                         double maxVal =  std::numeric_limits<double>::infinity())
{
    while (true) {
        std::cout << prompt;

        double value;
        if (!(in >> value)) {
            std::cout << "Invalid input. Please enter a valid number.\n";
            in.clear();
            in.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue;
        }

        in.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        if (value < minVal || value > maxVal) {
            std::cout << "Value must be in range [" << minVal << ", " << maxVal << "].\n";
            continue;
        }

        return value;
    }
}

inline std::string readLine(std::istream& in,
                            const std::string& prompt,
                            bool allowEmpty = false)
{
    while (true) {
        std::cout << prompt;

        std::string input;
        std::getline(in >> std::ws, input); // eat leading whitespace/newlines safely

        if (!allowEmpty && input.empty()) {
            std::cout << "Input cannot be empty. Please try again.\n";
            continue;
        }
        return input;
    }
}

// ===== Convenience overloads (keep your old calls working) =====
inline int readInt(const std::string& prompt,
                   int minVal = std::numeric_limits<int>::min(),
                   int maxVal = std::numeric_limits<int>::max())
{
    return readInt(std::cin, prompt, minVal, maxVal);
}

inline double readDouble(const std::string& prompt,
                         double minVal = -std::numeric_limits<double>::infinity(),
                         double maxVal =  std::numeric_limits<double>::infinity())
{
    return readDouble(std::cin, prompt, minVal, maxVal);
}

inline std::string readLine(const std::string& prompt, bool allowEmpty = false)
{
    return readLine(std::cin, prompt, allowEmpty);
}