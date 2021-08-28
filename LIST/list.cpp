#include<iostream>
template<typename T>
class list {
public:
    list() {
        size = 0;
        head = nullptr;
    }
    void push_back(T value) {
        if(head == nullptr) {
            head = new Node<T>(value);
        } else {
            Node<T> * tmp = this->head;
            while(tmp->pNext != nullptr) {
                tmp = tmp->pNext;
            }
            tmp -> pNext = new Node<T>(value);
        }
        size++;
    }
    void push_front(T value) {
        head = new Node<T>(value,head);
        size++;
    }
    list (const list& other) {
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

    list &operator =(const list & other) {
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

    void printList() {
        if(head == nullptr) {
            std::cout << 0;
            return;
        }
        Node<T>* cur = head;
        std::cout << cur->data << " ";
        while (cur->pNext != nullptr)
        {
            cur = cur->pNext;
            std::cout << cur->data << " ";
        }
        std::cout<<std::endl;
    }
    void pop_front(){
        Node<T> * tmp = head;
        head = head->pNext;
        delete tmp;
        size--;
    }
    void clear() {
        while (size) {
            pop_front();
        }
    }
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
int main()
{
    list<int> mList;    
    mList.push_back(3);
    mList.push_back(9);
    mList.push_back(1);
    mList.push_back(1213);
    mList.push_front(23);
    mList.printList();
    list<int> mList2;    
    mList2.push_back(0);
    mList2.push_back(78);
    mList2.push_back(5);
    mList2.push_back(747);
    mList2 = mList;
    mList2.printList();
}
