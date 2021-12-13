#include "chessboard.h"
#include <iostream>

Empty::Empty()
{
    color = empty ;
    name = EMPTY ;
}
King::King(Color c)
{
    color = c ;
    name = KING ;
}
Queen::Queen(Color c)
{
    color = c ;
    name = QUEEN ;
}
Rook::Rook(Color c)
{
    color = c ;
    name = ROOK ;
}
Bishop::Bishop(Color c)
{
    color = c ;
    name = BISHOP ;
}
Knight::Knight(Color c)
{
    color = c ;
    name = KNIGHT ;
}
Pawn::Pawn(Color c)
{
    color = c ;
    name = PAWN ;
}

Name Piece::get_name() const
{
    return name ;
}

Color Piece::get_color() const
{
    return color ;
}

chessboard_square::chessboard_square()
{
    piece = new Empty() ;
}

void chessboard_square::set_piece (Piece * p)
{
    piece = p ;
}

void Piece::set_px(size_t x)
{
    m_px = x ;
}

void Piece::set_py(size_t y)
{
    m_py = y ;
}
void chessboard_square::set_x(size_t x)
{
    piece->set_px(x) ;
}

void chessboard_square::set_y(size_t y)
{
    piece->set_py(y) ;
}

Chessboard::Chessboard()
{
    chess[0][0].set_piece(new Rook(white)) ;
    chess[0][0].set_x(0) ;
    chess[0][0].set_y(0) ;

    chess[0][1].set_piece(new Knight(white)) ;
    chess[0][1].set_x(0) ;
    chess[0][1].set_y(1) ;

    chess[0][2].set_piece(new Bishop(white)) ;
    chess[0][2].set_x(0) ;
    chess[0][2].set_y(2) ;

    chess[0][3].set_piece(new Queen(white)) ;
    chess[0][3].set_x(0) ;
    chess[0][3].set_y(3) ;

    chess[0][4].set_piece(new King(white)) ;
    chess[0][4].set_x(0) ;
    chess[0][4].set_y(4) ;

    chess[0][5].set_piece(new Bishop(white)) ;
    chess[0][5].set_x(0) ;
    chess[0][5].set_y(5) ;

    chess[0][6].set_piece(new Knight(white)) ;
    chess[0][6].set_x(0) ;
    chess[0][6].set_y(6) ;

    chess[0][7].set_piece(new Rook(white)) ;
    chess[0][7].set_x(0) ;
    chess[0][7].set_y(7) ;

    for(int i = 0; i < 8; ++i)
    {
        chess[1][i].set_piece(new Pawn(white)) ;
        chess[1][i].set_x(1) ;
        chess[1][i].set_y(i) ;
        chess[6][i].set_piece(new Pawn(black)) ;
        chess[6][i].set_x(6) ;
        chess[6][i].set_y(i) ;
    }
    chess[7][0].set_piece(new Rook(black)) ;
    chess[7][0].set_x(7) ;
    chess[7][0].set_y(0) ;

    chess[7][1].set_piece(new Knight(black)) ;
    chess[7][1].set_x(7) ;
    chess[7][1].set_y(1) ;

    chess[7][2].set_piece(new Bishop(black)) ;
    chess[7][2].set_x(7) ;
    chess[7][2].set_y(2) ;

    chess[7][3].set_piece(new Queen(black)) ;
    chess[7][3].set_x(7) ;
    chess[7][3].set_y(3) ;

    chess[7][4].set_piece(new King(black)) ;
    chess[7][4].set_x(7) ;
    chess[7][4].set_y(4) ;

    chess[7][5].set_piece(new Bishop(black)) ;
    chess[7][5].set_x(7) ;
    chess[7][5].set_y(5) ;

    chess[7][6].set_piece(new Knight(black)) ;
    chess[7][6].set_x(7) ;
    chess[7][6].set_y(6) ;

    chess[7][7].set_piece(new Rook(black)) ;
    chess[7][7].set_x(7) ;
    chess[7][7].set_y(7) ;
    for(int i = 2; i < 6; ++i) {
        for (int j = 0; j < 8; ++j) {
            chess[i][j].set_x(i) ;
            chess[i][j].set_y(j) ;
        }
    }
}

Piece * chessboard_square::get_piece()
{
    return piece ;
}

bool Pawn::move(size_t x, size_t y)
{
    return true ;
}
bool Knight::move(size_t x, size_t y)
{
    return true ;
}
bool King::move(size_t x, size_t y)
{
    return true ;
}
bool Queen::move(size_t x, size_t y)
{
    return true ;
}
bool Rook::move(size_t x, size_t y)
{
    return true ;
}
bool Bishop::move(size_t x, size_t y)
{
    return true ;
}

Piece& Piece::operator=(Piece & other)
{
    this->color = other.color ;
    this->m_px = other.m_px ;
    this->m_py = other.m_py ;
    return *this ;
}

chessboard_square & chessboard_square::operator=(chessboard_square & other)
{
    *(this->piece) = *(other.piece) ;
    return *this ;
}

void Chessboard::do_move()
{
    int px ;
    int py ;
    int x ;
    int y ;
    while(true)
    {
        std::cout << "enter figure x: " ;
        std::cin >> px ;
        std::cout << "enter figure y: " ;
        std::cin >> py ;
        std::cout << "enter board x: " ;
        std::cin >> x ;
        std::cout << "enter board y: " ;
        std::cin >> y ;
        if(!std::cin.good()) {
            std::cin.clear() ;
            std::cin.get() ;
            std::cout << std::endl ;
            continue ;
        } else {
            break ;
        }
    }
    if(chess[px][py].get_piece()->move(x,y))
    {

    }

}

void Chessboard::print_board()
{
    std::cout << " y:  a  b  c  d  e  f  g  h "<<std::endl;
    std::cout << "x:\n";
    for(int i = 0; i < 8;i++) {
        std::cout<<""<< i + 1 <<":  ";
        for(int j = 0;j < 8;j++)
        {
            switch (chess[i][j].get_piece()->get_name())
            {
                case KING:
                    (chess[i][j].get_piece()->get_color() == white) ? std::cout << "|♚|" : std::cout << "|♔|";
                    break;
                case QUEEN:
                    (chess[i][j].get_piece()->get_color() == white) ? std::cout << "|♛|" : std::cout << "|♕|";
                    break;
                case BISHOP:
                    (chess[i][j].get_piece()->get_color() == white) ? std::cout << "|♝|" : std::cout << "|♗|";
                    break;
                case KNIGHT:
                    (chess[i][j].get_piece()->get_color() == white) ? std::cout << "|♞|" : std::cout << "|♘|";
                    break;
                case ROOK:
                    (chess[i][j].get_piece()->get_color() == white) ? std::cout << "|♜|" : std::cout << "|♖|";
                    break;
                case PAWN:
                    (chess[i][j].get_piece()->get_color() == white) ? std::cout << "|♟|" : std::cout << "|♙|";
                    break;
                case EMPTY:
                    std::cout << "|-|";
                    break;
                default:
                    break;
            }
        }
        std::cout << "  " << i + 1 << std::endl ;
    }
    std::cout << "     a  b  c  d  e  f  g  h "<<std::endl;

}

int main()
{
    Chessboard obj ;
    obj.print_board() ;
    obj.do_move() ;

}