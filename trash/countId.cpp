#include<iostream>
class countId {
	static int id ;
	int x ;
public:
	countId() ;
	int getId() const ;
} ;
int countId::id = 0 ;
countId::countId() {
	x = ++id;
}
int countId::getId() const {
	return x ;
}
int main()
{
	countId obj1 ;
	countId obj2 ;
	countId obj3 ;
	std::cout << obj1.getId() << std::endl ;
	std::cout << obj2.getId() << std::endl ;
	std::cout << obj3.getId() << std::endl ;
}
