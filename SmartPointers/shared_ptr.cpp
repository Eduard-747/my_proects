    
#include<iostream>
class ControlBlock{
public:
    void operator++()
    {
      ++count;
    }
    void operator--()
    {
      --count;
    }
    int getCount() const { return count; }
private:
    int count {};   

};

template <typename T>
class Shared_Ptr {
public:
    Shared_Ptr(T * ptr) {

        mPtr = ptr;
        mCount = new ControlBlock();
        if(ptr) {
            ++*mCount;
        }
    }
    Shared_Ptr(Shared_Ptr<T>& other) {
        if(other.mCount->getCount() == 0) {
            mPtr = nullptr;
        } else {
            mPtr = other.mPtr;
            mCount = other.mCount;
            ++*mCount;
        }
    }
    T & operator *()
    {

        return *mPtr;
    }

    ~Shared_Ptr() {
        --*mCount;
        if(mCount->getCount() == 0) { 

            delete mCount;
            delete mPtr;
            std::cout << "destruktor\n";
        }
    }
    
private:
    ControlBlock * mCount;
    T * mPtr;
};

int  main()
{   
    std::cout<<"\n=======================\n";
    Shared_Ptr<int> p(new int(5));
    Shared_Ptr<int> cp(p);
    Shared_Ptr<int> c2(p);
    
    Shared_Ptr<int> f(new int(421));
    Shared_Ptr<int> fc(f);
    Shared_Ptr<int> fc2(f);
    
    std::cout<<"\n=======================\n";
}
