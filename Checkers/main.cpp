#include "checkers.cpp"
int main()
{
    Board obj;
    obj.print_board() ;
    while (obj.win())
    {
        obj.move() ;
        obj.print_board() ;
    }
    return 0 ;
}