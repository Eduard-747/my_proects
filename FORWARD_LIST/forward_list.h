#ifndef FORWARD_LIST_H
#define FORWARD_LIST_H

#include <iterator>

namespace myl {
    template<typename T>
    class forward_list {
    public:
        forward_list();
        forward_list (const forward_list& other);
        forward_list &operator =(const forward_list & other);
        forward_list (forward_list&& other);
        forward_list &operator =(forward_list && other);
        ~forward_list();
    public:
        void push_back(const T& value);
        void push_front(const T& value);
        void insert(const T& data,int index);
        void pop_front();
        void pop_back();
        void clear();
        void sort();
        int remove(const T&);
        void reverse();
        T& front();
        const T& front() const;
        bool empty() const;
        void traverse(void(*foo)(const T elem));
    private:
        template<typename Ti>
        class Node {
        public:
            Node * pNext;
            T data;
            Node(T data = T() , Node * pNext = nullptr) {
                this->data = data;
                this->pNext = pNext;
            }
        };
        int size;
        Node<T> *head;
    private:
        Node<T>* reverse(Node<T>* head)
        {
           if (head == nullptr || head->pNext == nullptr)
                return head;
            Node<T>* rest = reverse(head->pNext);
            head->pNext->pNext = head;
            head->pNext = nullptr;
            return rest;
        }
    public:
        class iterator: public std::iterator<std::forward_iterator_tag,T>
        {
        public:
            iterator(Node<T> * node = nullptr);
            iterator(const iterator&);
            iterator& operator=(const iterator&);
            iterator(iterator&&);
            iterator& operator=(iterator&&);
        public:
            iterator& operator++();
            iterator operator++(int);
            bool operator!=(const iterator& other) const;
            const T& operator*() const;
            T& operator*();
        private:
            Node<T>* it;
        };
    public:
        iterator begin();
        iterator end();
    };
}

#include "forward_list.hpp"

#endif
