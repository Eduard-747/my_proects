#include<iostream>
template<typename T>
class vector
{
public:
    vector();
    vector(int colum,T value);
    void push_back(T value);
    void push_back(T value,int index);
    void pop_back();
    T getSize() const { return size; }
    T getCapacity() const { return capacity; }
    vector(const vector & other);
    vector & operator=(const vector & other);
    T operator[] (int index);
    void shrink_to_fit();
    ~vector();
private:
    T * arr;
    int size;
    int capacity;
};

template<typename T>
vector<T>::vector()
{
    size = 0;
    capacity = 1;
    arr = new T[1];
}

template<typename T>
vector<T>::vector(int colum,T value)
{
    size = colum;
    capacity = size * 2;
    arr = new T[capacity];
    for(int i = 0; i < size;i++) {
        arr[i] = value;
    }
}

template<typename T>
vector<T>::~vector()
{
    delete [] arr;    
}

template<typename T>
void vector<T>::push_back(T value) {
    if(capacity == size) {
        T *tmp = new T[capacity * 2];
        for(int i = 0; i < capacity;i++) {
            tmp[i] = arr[i];
        }
        delete [] arr;
        arr = tmp;
        capacity *= 2;
        tmp = nullptr;
    }
    arr[size] = value;
    size++;
}

template<typename T>
void vector<T>::push_back(T value,int index) {
    if(index == capacity) {
        push_back(value);
    } else {
        arr[index] = value;
    }
}

template<typename T>
void vector<T>::pop_back() {
    T *tmp = new T[capacity - 1];
    for(int i = 0; i < size - 1; i++) {
        tmp[i] = arr[i];
    }
    delete [] arr;
    arr = tmp;
    capacity--;
    size--;
}

template<typename T>
vector<T>::vector(const vector & other) {
    this->size = other.size;
    this->capacity = other.capacity;
    this->arr = new T [this->capacity];
    for(int i = 0;i < size; i++){
    
        this->arr[i] = other.arr[i];
    }
}

template<typename T>
vector<T> & vector<T>::operator=(const vector & other){
    if(this == &other) {
        return * this;
    }
    delete [] arr;
    this->size = other.size;
    this->capacity = other.capacity;
    this->arr = new T [other.capacity];
    for(int i = 0;i < size; i++){
    
        this->arr[i] = other.arr[i];
    }
    return *this;   
}

template<typename T>
T vector<T>::operator[](int index) {
    return arr[index];
}

template<typename T>
void vector<T>::shrink_to_fit() {
    capacity = size;
}
