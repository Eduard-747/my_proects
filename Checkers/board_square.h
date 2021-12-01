#ifndef BOARD_SQUARE_
#define BOARD_SQUARE_

enum Color { empty , white , black } ;
class Board_Square
{
public:
    void set_fx(int x) ;
    void set_fy(int y) ;
    int get_fx() const ;
    int get_fy() const ;
    void set_color(Color) ;
    Color get_color() const ;
private:
    class Figure 
    {
    public:
        int fx ;
        int fy ;
        Color color {empty} ;
    } ;
    Figure figure ;
} ;

#endif