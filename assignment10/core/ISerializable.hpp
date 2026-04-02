#pragma once
#include <iostream>

class ISerializable {
public:
    virtual ~ISerializable() = default;

    // PURE VIRTUAL (abstract interface)
    virtual void input(std::istream& in) = 0;
    virtual void output(std::ostream& out) const = 0;
};