#ifndef CHESSBOARD_SQUARE_
#define CHESSBOARD_SQUARE_
#include "piece.h"
class chessboard_square
{
public:
    chessboard_square() ;
    chessboard_square(size_t,size_t) ;
    void set_x(size_t x) ;
    void set_y(size_t y) ;
    size_t get_x() const ;
    size_t get_y() const ;
    void set_piece(Piece *) ;
    Piece * get_piece()  ;
    chessboard_square& operator=(chessboard_square&) ;
private:
    Piece * piece ;
};

#endif