#include<iostream>
#include"board.h"

void Board_Square::set_fx(int x) {
    figure.fx = x ;
}
void Board_Square::set_fy(int y) {
    figure.fy = y ;
}
int Board_Square::get_fx() const {
    return figure.fx ;
}
int Board_Square::get_fy() const {
    return figure.fy ;
}
void Board_Square::set_color(Color color) 
{
    figure.color = color ;
}
Color Board_Square::get_color() const 
{
    return figure.color ;
}
void Board::move() 
{
    int fx ;
    int fy ;
    int x ;
    int y ;
    while(true) 
    {
        std::cout << "enter figure x: " ;
        std::cin >> fx ;
        std::cout << "enter figure y: " ;
        std::cin >> fy ;
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
    if(turn) {
    if((board[x][y].get_color() == empty && board[fx][fy].get_color() == white) && (x == fx - 1 && (y == fy - 1 || y == fy + 1 ))) {
        board[x][y].set_color( board[fx][fy].get_color() ) ;
        board[fx][fy].set_color(empty) ;
        turn = false ;
        return ;
    } else if((board[x][y].get_color() == empty && board[fx][fy].get_color() == white) && (x == fx - 2 || x == fx + 2 && (y == fy - 2 || y == fy + 2)) ) {
        if(board[(x+fx)/2][(y+fy)/2].get_color() == black) {
            board[x][y].set_color(board[fx][fy].get_color()) ;
            board[(x+fx)/2][(y+fy)/2].set_color(empty) ;
            board[fx][fy].set_color(empty) ;
            turn = false ;
            --count_black ;
            return ;
        }
    }
    }else {
    if((board[x][y].get_color() == empty && board[fx][fy].get_color() == black) && (x == fx + 1 &&( y == fy - 1 || y == fy + 1 ))) {
        board[x][y].set_color( board[fx][fy].get_color()) ;
        board[fx][fy].set_color(empty) ;
        turn = true ;
        return ;
    } else if((board[x][y].get_color() == empty && board[fx][fy].get_color() == black) && (x == fx + 2 || x == fx - 2 && (y == fy - 2 || y == fy + 2 ))) {
        if(board[(x+fx)/2][(y+fy)/2].get_color() == white) {
            board[x][y].set_color(board[fx][fy].get_color()) ;
            board[(x+fx)/2][(y+fy)/2].set_color(empty) ;
            board[fx][fy].set_color(empty) ;
            turn = true ;
            --count_white ;
            return ;
        }
    }
    }
    return ;
}
Board::Board() 
{
    for(int i = 0 ; i < 3 ; ++i)
    {
        for(int j = i % 2 ; j < 8 ; j+=2)
        {
            board[i][j].set_color(black) ;
            board[i][j].set_fx(i) ;
            board[i][j].set_fy(j) ;
        }
    }
    for(int i = 5 ; i < 8 ; ++i)
    {
        for(int j = i % 2 ; j < 8 ; j+=2)
        {
            board[i][j].set_color(white) ;
            board[i][j].set_fx(i + 5) ;
            board[i][j].set_fy(j) ;
        }
    }
}
void Board::print_board() 
{
    std::system("clear") ;
    std::cout << " y:  0  1  2  3  4  5  6  7 "<<std::endl;
    std::cout << "x:\n";
    for(int i = 0 ; i < 8 ; ++i) {
        std::cout << "" << i  << ":  ";
        for(int j = 0; j < 8; ++j) 
        {
            switch (board[i][j].get_color())
            {
            case white :
                std::cout << " " << "⛂" << " ";    
                break;
            case black :
                std::cout << " " << "⛀" << " ";
                break ;
            case empty :
                std::cout << " " << "-" << " ";
                break ;
            default:
                break;
            }
        }
        std::cout << std::endl ;
    }
    std::cout << std::endl ;
    std::cout << std::endl ;
}
bool Board::win() 
{
    if(!count_black) {
        std::cout << "\nWin White!!\n" ;
        return false ;
    }
    if(!count_white) {
        std::cout << "\nWin Black!!\n" ;
        return false ;
    }
    return true ;
}

