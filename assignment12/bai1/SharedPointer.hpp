#pragma once

#include <cstddef>
#include <utility>
#include "ControlBlock.hpp"

template<typename T>
class WeakPointer;

template<typename T>
class SharedPointer {
private:
    ControlBlock<T>* control;

    void release() {
        if (control == nullptr) {
            return;
        }

        if (control->strong_count > 0) {
            --control->strong_count;
        }

        if (control->strong_count == 0) {
            delete control->ptr;
            control->ptr = nullptr;

            if (control->weak_count == 0) {
                delete control;
                control = nullptr;
                return;
            }
        }

        control = nullptr;
    }

    explicit SharedPointer(ControlBlock<T>* cb) : control(cb) {
        if (control != nullptr) {
            ++control->strong_count;
        }
    }

    friend class WeakPointer<T>;

public:
    SharedPointer() : control(nullptr) {
    }

    explicit SharedPointer(T* ptr) {
        if (ptr != nullptr) {
            control = new ControlBlock<T>(ptr);
        } else {
            control = nullptr;
        }
    }

    SharedPointer(const SharedPointer& other) : control(other.control) {
        if (control != nullptr) {
            ++control->strong_count;
        }
    }

    SharedPointer(SharedPointer&& other) noexcept : control(other.control) {
        other.control = nullptr;
    }

    ~SharedPointer() {
        release();
    }

    SharedPointer& operator=(const SharedPointer& other) {
        if (this != &other) {
            release();
            control = other.control;
            if (control != nullptr) {
                ++control->strong_count;
            }
        }
        return *this;
    }

    SharedPointer& operator=(SharedPointer&& other) noexcept {
        if (this != &other) {
            release();
            control = other.control;
            other.control = nullptr;
        }
        return *this;
    }

    T& operator*() const {
        return *(control->ptr);
    }

    T* operator->() const {
        return control->ptr;
    }

    T* get() const {
        return (control != nullptr) ? control->ptr : nullptr;
    }

    std::size_t use_count() const {
        return (control != nullptr) ? control->strong_count : 0;
    }

    bool unique() const {
        return use_count() == 1;
    }

    explicit operator bool() const {
        return get() != nullptr;
    }

    void reset() {
        release();
    }

    void reset(T* ptr) {
        release();
        if (ptr != nullptr) {
            control = new ControlBlock<T>(ptr);
        }
    }
};