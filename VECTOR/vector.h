#include<iostream>
template<typename T>
class vector
{
public:
    vector() ;
    vector(int colum,T value) ;
    vector(const vector & other) ;
    vector & operator=(const vector & other) ;
    T operator[] (int index) ;
    ~vector() ;
public:
    void push_back(T value) ;
    void push_back(T value,int index) ;
    void pop_back() ;
    T getSize() const { return size; }
    T getCapacity() const { return capacity; }
    void shrink_to_fit() ;
public:

    class iterator {
    public:
        iterator(T * p = nullptr) { iter = p ; }
        iterator(const iterator& it) {
            iter = it.iter ;
        }
        iterator & operator= (const iterator& it) {
            if(this == &it) { return *this ; }
            this->iter = it.iter ;
            return *this ;
        }
        iterator operator+(const int& add) {
            iterator it ;
            it.iter = iter + add ;
            return it ;
        }
        iterator operator-(const int& sub) {
            iterator it ;
            it.iter = iter - sub ;
            return it ;
        }
        iterator& operator+=(const int& add) {
            this->iter += add ;
            return *this ;
        }
        iterator& operator-=(const int& sub) {
            this->iter -= sub ;
            return *this ;
        }
        T& operator++() {
            ++iter ;
            return *iter ;
        }
        T& operator++(int) {
            T *tmp = iter ;
            ++iter ;
            return *tmp ;
        }
        T& operator--() {
            --iter ;
            return *iter ;
        }
        T& operator--(int) {
            T *tmp = iter ;
            --iter ;
            return *tmp ;
        }
        bool operator!=(const iterator& other) const {
            return this->iter != other.iter ;
        }
        T& operator*() const {
            return *iter ;
        }
    private:
        T * iter ;
    } ;
    iterator begin() 
    {
       iterator it(arr) ;
       return it ;
    }
    iterator end() 
    {
        iterator it(arr + size) ;
        return it ;
    }
    void insert(iterator& iter,const T& value) {
        if(size < capacity) {
            for(iterator i = this->end(); i != iter ; --i) {
                *i = *(i - 1);
            }
            *iter = value ;
        }
        else
        {
            capacity *= 2;
            T* tmp = new T [capacity];
            int j = 0 ;
            for(auto i = this->begin();i != iter ;++i )
            {
                tmp[j++] = *i ;
            }
            tmp[j] = value ;
            for(;iter != this->end(); ++iter)
            {
                tmp[++j] = *iter ;
            }
            delete[] arr ;
            arr = tmp ;
        }
        size++ ;
    }

    void erease(iterator& iter) {
        T *tmp = new T[capacity];
        int i = 0 ;
        for(i = 0; i < size; i++) {
            if(arr[i] == *iter) {
                break ;
            } 
            tmp[i] = arr[i] ;
        }
        for(int j = i + 1;j < size; ++j) {
            tmp[i] = arr[j] ;
            i++ ;
        }
        delete [] arr;
        arr = tmp;
        tmp = nullptr;
        size--;
    }
private:
    T * arr ;
    int size ;
    int capacity ;
};