#ifndef BOARD_
#define BOARD_
#include "board_square.h"
class Board
{
public:
    Board() ;
    void print_board() ;
    void move() ;
    bool win() ;
    
private:
    Board_Square board [8][8] ;
    bool turn { true } ;
    int count_white { 12 } ;
    int count_black { 12 } ;
} ;

#endif