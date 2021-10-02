#pragma once
#include <iostream>
#include <memory>

template <class T>
class unique_ptr {
public:
    unique_ptr() = default;

    unique_ptr(std::nullptr_t)
        : ptr(nullptr){};

    explicit unique_ptr(T* wsk)
        : ptr(wsk){};

    ~unique_ptr() {
        delete ptr;
    }

    T* operator->() {
        return ptr;
    }

    T* get() const noexcept {
        return ptr;
    }

    T* release() noexcept {
        T* cptr = ptr;
        ptr = nullptr;
        return cptr;
    }

private:
    T* ptr;
};
