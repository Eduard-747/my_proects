#include "list.h"
template<typename T>
void list<T>::push_back(T value) 
{
    if(head == nullptr) {
        head = new Node<T>(value);
    } else {
        Node<T> * tmp = this->head;
        while(tmp->pNext != nullptr) 
        {
            tmp = tmp->pNext;
        }
        tmp -> pNext = new Node<T>(value);
    }
    size++;
}

template<typename T>
void list<T>::push_front(T value)
{
    head = new Node<T>(value,head);
    size++;
}

template<typename T>
list<T>::list(const list& other) 
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
list<T> & list<T>::operator =(const list & other) 
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
void list<T>::insert(T data,int index) 
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
void list<T>::printList() 
{
    if(head == nullptr) {
        std::cout << 0;
        return;
    }
    Node<T>* cur = head;
    while (cur)
    {
        std::cout << cur->data << " ";
        cur = cur->pNext;
    }
    std::cout << std::endl;
}

template<typename T>
void list<T>::pop_front()
{
    Node<T> * tmp = head;
    head = head->pNext;
    delete tmp;
    size--;
}

template<typename T>
void list<T>::pop_back() 
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
void list<T>::clear() 
{
    while (size) 
    {
        pop_front();
    }
}

int main()
{
    list<int> mList;    
    mList.push_back(3);
    mList.push_back(9);
    mList.push_back(1);
    mList.push_back(1213);
    mList.push_back(23);
    mList.pop_back();
    
    list<int> mList2;
    mList2.push_back(9);
    mList2.push_back(1);
    mList2.push_back(1213);
    mList2.push_back(23);
    mList = mList2 ;
    mList.printList();
}
