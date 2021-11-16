#include <iostream>
class Rectangle {
public:
    virtual void set_y(int y) ;
    virtual void set_x(int x) ;
    int area() ;
private:
    int x ;
    int y ;
};
void Rectangle::set_x(int x) {
    this->x = x ;
}
void Rectangle::set_y(int y) {
    this->y = y ;
}
int Rectangle::area() {
    return  x * y ;
}

class Square : public Rectangle
{
public:
    void set_x(int) override ;
    void set_y(int) override ;
};
void Square::set_x(int x) {
    Rectangle::set_y(x) ;
    Rectangle::set_x(x) ;
}
void Square::set_y(int y) {
    Rectangle::set_y(y) ;
    Rectangle::set_x(y) ;
}
int main()
{
    Square obj ;
    obj.set_x(3) ;
    Rectangle rec ;
    rec.set_x(5) ;
    rec.set_y(3) ;
    std::cout << obj.area() << std::endl ;
    std::cout << rec.area() << std::endl ;
    Rectangle * p = new Square ;
    p->set_x(2) ;
    p->set_y(1) ;
    std::cout << p->area() << std::endl ;
    return 0 ;
}