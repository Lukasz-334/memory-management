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
        : ptr(wsk){

          };

    unique_ptr(const unique_ptr& ptr) = delete;

    unique_ptr(unique_ptr&& moved_ptr) {
        ptr = moved_ptr.ptr;
        moved_ptr.ptr = nullptr;
    }

    unique_ptr& operator=(const unique_ptr& moved_ptr) = delete;

    unique_ptr& operator=(unique_ptr&& moved_ptr) {
        if (&moved_ptr != this) {
            if (ptr) {
                delete ptr;
            }
            if (moved_ptr.ptr) {
                ptr = moved_ptr.ptr;
                moved_ptr.ptr = nullptr;
            }
        }
        return *this;
    }

    ~unique_ptr() {
        delete ptr;
    }

    T& operator*(){
        return *ptr;
    }

    T* operator->() {
        return ptr;
    }

    T* get() const noexcept {
        return ptr;
    }

    T* release() noexcept {
        T* current_ptr = ptr;
        ptr = nullptr;
        return current_ptr;
    }

    void reset(T* current_ptr) noexcept {
        T* old_ptr = ptr;
        ptr = current_ptr;
        if (old_ptr) {
            delete old_ptr;
        }
    }

    void reset() {
        delete ptr;
        ptr = nullptr;
    }

private:
    T* ptr = nullptr;
};
