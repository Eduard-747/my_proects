#ifndef CHESSBOARD_
#define CHESSBOARD_
#include "chessboard_square.h"
class Chessboard {
public:
    Chessboard() ;
    void print_board() ;
    void do_move() ;
private:
    chessboard_square chess[8][8] ;
};

#endif