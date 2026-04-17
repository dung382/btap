#pragma once

#include <cstddef>

template<typename T>
struct ControlBlock {
    T* ptr;
    std::size_t strong_count;
    std::size_t weak_count;

    explicit ControlBlock(T* p)
        : ptr(p), strong_count(1), weak_count(0) {
    }
};