template <typename T>
unique_ptr<T>::unique_ptr()
{
    ptr = nullptr;
}

template <typename T>
unique_ptr<T>::unique_ptr(T * p)
{
    ptr = p;
}

template <typename T>
unique_ptr<T>::~unique_ptr()
{
    delete ptr;
    ptr = nullptr;
}

template <typename T>
T& unique_ptr<T>::operator*()
{
    return *ptr;
}

template <typename T>
T* unique_ptr<T>::operator->() const
{
    return ptr;
}

template <typename T>
unique_ptr<T>::unique_ptr(unique_ptr<T>&& r) noexcept
{
    ptr = r.ptr;
    r.ptr = nullptr;
}

template <typename T>
unique_ptr<T>& unique_ptr<T>::operator=(unique_ptr<T>&& r) noexcept
{
    delete ptr;
    ptr = r.ptr;
    r.ptr = nullptr;
    return *this;
}

template <typename T>
T* unique_ptr<T>::get() const
{
    return ptr;
}

template <typename T>
void unique_ptr<T>::reset() noexcept
{
    delete ptr;
    ptr = nullptr;
}