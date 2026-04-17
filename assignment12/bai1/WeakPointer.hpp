#pragma once

#include <cstddef>
#include "SharedPointer.hpp"

template<typename T>
class WeakPointer {
private:
    ControlBlock<T>* control;

    void release() {
        if (control == nullptr) {
            return;
        }

        if (control->weak_count > 0) {
            --control->weak_count;
        }

        if (control->strong_count == 0 && control->weak_count == 0) {
            delete control;
        }

        control = nullptr;
    }

public:
    WeakPointer() : control(nullptr) {
    }

    WeakPointer(const SharedPointer<T>& shared) : control(shared.control) {
        if (control != nullptr) {
            ++control->weak_count;
        }
    }

    WeakPointer(const WeakPointer& other) : control(other.control) {
        if (control != nullptr) {
            ++control->weak_count;
        }
    }

    WeakPointer(WeakPointer&& other) noexcept : control(other.control) {
        other.control = nullptr;
    }

    ~WeakPointer() {
        release();
    }

    WeakPointer& operator=(const WeakPointer& other) {
        if (this != &other) {
            release();
            control = other.control;
            if (control != nullptr) {
                ++control->weak_count;
            }
        }
        return *this;
    }

    WeakPointer& operator=(WeakPointer&& other) noexcept {
        if (this != &other) {
            release();
            control = other.control;
            other.control = nullptr;
        }
        return *this;
    }

    WeakPointer& operator=(const SharedPointer<T>& shared) {
        release();
        control = shared.control;
        if (control != nullptr) {
            ++control->weak_count;
        }
        return *this;
    }

    bool expired() const {
        return (control == nullptr || control->strong_count == 0);
    }

    std::size_t use_count() const {
        return (control != nullptr) ? control->strong_count : 0;
    }

    SharedPointer<T> lock() const {
        if (expired()) {
            return SharedPointer<T>();
        }

        SharedPointer<T> temp;
        temp.control = control;
        ++temp.control->strong_count;
        return temp;
    }
};