#include <iostream>
class Rectangle {
public:
    void set_y(int y) ;
    void set_x(int x) ;
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
    void set(int x) ;
private:
    void set_x(int ) ;
    void set_y(int ) ;
};
void Square::set(int x) {
    Rectangle::set_y(x) ;
    Rectangle::set_x(x) ;
}
int main()
{
    Square obj ;
    obj.set(3) ;
    Rectangle rec ;
    rec.set_x(5) ;
    rec.set_y(3) ;
    std::cout << obj.area() << std::endl ;
    std::cout << rec.area() << std::endl ;

    return 0 ;
}
