#ifndef UNIQUE_PTR_H
#define UNIQUE_PTR_H

template <typename T>
class unique_ptr
{
public:
    unique_ptr();
    unique_ptr(T * p);
    T& operator*();
    T* operator->() const;
    unique_ptr(unique_ptr&&) noexcept;
    unique_ptr& operator=(unique_ptr&&) noexcept;
    ~unique_ptr();
public:
    T* get() const;
    void reset() noexcept;
private:
    unique_ptr(const unique_ptr&) = delete;
    unique_ptr& operator=(const unique_ptr&) = delete;
private:
    T * ptr;
};

#include "unique_ptr.hpp"

#endif