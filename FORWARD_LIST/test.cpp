#include "forward_list.h"

#include <iostream>

void print(int f)
{
    std::cout << f ;
}

int main()
{
    myl::forward_list<int> mList;
    mList.push_front(7);
    mList.push_front(4);
    mList.push_front(7);
    mList.push_front(9);
    std::cout << mList.remove(7) << std::endl;
    mList.sort();
    mList.reverse();
    mList.traverse(print);
    std::cout << std::endl;
}
