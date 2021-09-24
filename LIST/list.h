#include<iostream>
template<typename T>
class list {
public:
    list() {
        size = 0;
        head = nullptr;
    }

    void push_back(T value) ;
    void push_front(T value) ;
    list (const list& other) ;
    list &operator =(const list & other) ;
    void insert(T data,int index) ;
    void printList() ;
    void pop_front() ;
    void pop_back() ;
    void clear() ;

    ~list() {
        clear();
    }   
private:
    template<typename Ti>
    class Node {
    public:
        Node * pNext;
        T data;
        Node(T data = T(),Node *pNext = nullptr) {
            this->data = data;
            this->pNext = pNext;
        }
    };
    int size;
    Node<T> *head;
};
