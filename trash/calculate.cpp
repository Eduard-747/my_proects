#include<iostream>

class Calculator{
public:
	void set(int x , int y) {
		this->x = x ;
		this->y = y ;
	}
	int add() const {
		return x + y ;
	}
	int sub() const {
		return x - y ;
	}
	int mul() const {
		return x * y ;
	}
	int div() const {
		return x / y;
	}
private:
	int x ;
	int y ;
 };

int main()
{
	Calculator obj ;
	obj.set(10,5) ;
	std::cout << obj.add() << std::endl;
	std::cout << obj.sub() << std::endl;
	std::cout << obj.mul() << std::endl;
	std::cout << obj.div() << std::endl;
}
