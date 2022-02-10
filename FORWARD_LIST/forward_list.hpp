#include <iostream>

template<typename T>
myl::forward_list<T>::forward_list() 
{
    head = nullptr;
    size = 0;
}

template<typename T>
myl::forward_list<T>::~forward_list() 
{
    clear();
}

template<typename T>
T& myl::forward_list<T>::front()
{
    return head->data;
}

template<typename T>
const T& myl::forward_list<T>::front() const
{
    return head->data;
}

template<typename T>
void myl::forward_list<T>::traverse(void(*foo)(const T elem))
{
    Node<T>* cur = head;
    while (cur)
    {
        foo(cur->data);
        cur = cur->pNext;
    }
}

template<typename T>
void myl::forward_list<T>::sort()
{
    Node<T> * dm = new Node<T>;
    Node<T> * curr = dm;
    while(head)
    {
        Node<T> * tmp = head->pNext;
        curr = dm;
        while(curr->pNext && curr->pNext->data <= head->data){
            curr = curr->pNext;
        }
        head->pNext = curr->pNext;
        curr->pNext = head;
        head = tmp;
    }
    head = dm->pNext;
}

template<typename T>
void myl::forward_list<T>::reverse()
{
    head = this->reverse(head);
}

 
template<typename T>
void myl::forward_list<T>::push_back(const T& value) 
{
    if(head == nullptr) {
        head = new Node<T>(value);
    } else {
        Node<T> * tmp = this->head;
        while(tmp->pNext != nullptr) 
        {
            tmp = tmp->pNext;
        }
        tmp->pNext = new Node<T>(value);
    }
    size++;
}

template<typename T>
void myl::forward_list<T>::push_front(const T& value)
{
    head = new Node<T>(value,head);
    size++;
}

template<typename T>
int myl::forward_list<T>::remove(const T& value)
{
    Node<T> * prev = nullptr;
    Node<T> * curr = head;
    int count{};
    while(curr)
    {
        if(curr->data == value)
        {
            if(!prev) head = curr->pNext;
            else {
                ++count;
                prev->pNext = curr->pNext;
            }
        }
        else prev = curr;
        curr = curr->pNext;
    }
    size -= count;
    return count;
}

template<typename T>
bool myl::forward_list<T>::empty() const
{
    return !size;
}

template<typename T>
myl::forward_list<T>::forward_list(const forward_list& other) 
{
    this->size = other.size;
    this->head = other.head;
    Node<T> * tmp = other.head;
    Node<T> * cur = head;
    while (tmp->pNext != nullptr)
    {
        tmp = tmp->pNext;
        cur = new Node<T>(tmp->data);
        cur = cur->pNext;
    }
}

template<typename T>
myl::forward_list<T> & myl::forward_list<T>::operator =(const forward_list & other) 
{
    if(this == &other) {
        return *this; 
    }
    clear();
    this->size = other.size;
    this->head = new Node<T>(other.head->data);
    Node<T> * tmp = other.head->pNext;
    Node<T>* cur = head;
    while (tmp != nullptr)
    {
        cur->pNext = new Node<T>(tmp->data);
        tmp = tmp->pNext;
        cur = cur->pNext;
    }
    return *this;
}

template<typename T>
myl::forward_list<T>::forward_list(forward_list&& other) 
{
    this->size = other.size;
    this->head = other.head;
    other.size = 0;
    other.head = nullptr;
}

template<typename T>
myl::forward_list<T> & myl::forward_list<T>::operator =(forward_list && other)
{
    clear();
    this->size = other.size;
    this->head = other.head;
    other.head = nullptr;
    other.size = 0;
    return *this;
}

template<typename T>
void myl::forward_list<T>::insert(const T& data,int index) 
{
    if(index == 0) {
        push_front(data);
    } else {
        Node<T> * prev = this->head;
        for(int i = 0;i < index - 1; i++) 
        {
            prev = prev->pNext;
        }
        Node<T> *newNode = new Node<T>(data,prev->pNext);
        prev = newNode;
        size++;
    }
}

template<typename T>
void myl::forward_list<T>::pop_front()
{
    Node<T> * tmp = head;
    head = head->pNext;
    delete tmp;
    size--;
}

template<typename T>
void myl::forward_list<T>::pop_back() 
{
    Node<T> * tmp1 = new Node<T>();
    tmp1 = tmp1->pNext;
    Node<T> * tmp2 = head;
    for(int i = 0;i < size - 1; ++i) 
    {
        tmp1 = new Node<T>(tmp2->data,tmp1) ;
        tmp2 = tmp2->pNext;
    }
    tmp2 = tmp2->pNext;
    while(tmp1) 
    {
        tmp2 = new Node<T>(tmp1->data,tmp2) ;
        tmp1 = tmp1 -> pNext;
    }
    head = tmp2;
    delete tmp1;
    --size;
}

template<typename T>
void myl::forward_list<T>::clear() 
{
    while (size) 
    {
        pop_front();
    }
}

template <typename T>
myl::forward_list<T>::iterator::iterator(T * p)
{
    it = p;
}

template <typename T>
myl::forward_list<T>::iterator::iterator(const iterator& other)
{
    it = other.it;
}

template <typename T>
myl::forward_list<T>::iterator::iterator(iterator&& other)
{
    it = other.it;
    other.it = nullptr;
}

template <typename T>
typename myl::forward_list<T>::iterator& myl::forward_list<T>::iterator::operator=(const iterator& other)
{
    it = other.it;
    return *this;
}

template <typename T>
typename myl::forward_list<T>::iterator& myl::forward_list<T>::iterator::operator=(iterator&& other)
{
    it = other.it;
    other.it = nullptr;
    return *this;
}

template <typename T>
T& myl::forward_list<T>::iterator::operator++()
{
    ++it;
    return *it;
}

template <typename T>
T& myl::forward_list<T>::iterator::operator++(int)
{
    T *tmp = it;
    ++it;
    return *tmp;
}

template <typename T>
bool myl::forward_list<T>::iterator::operator!=(const iterator& rv) const
{
    return this->it != rv.it;
}

template <typename T>
T& myl::forward_list<T>::iterator::operator*() const
{
        return *it;
}