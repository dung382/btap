#include "MathUtils.hpp"
#include <stdexcept>

double add(double a, double b) {
    return a + b;
}

double sub(double a, double b) {
    return a - b;
}

double mul(double a, double b) {
    return a * b;
}

double divi(double a, double b) {
    if (b == 0) {
        throw std::runtime_error("Divide by zero");
    }
    return a / b;
}