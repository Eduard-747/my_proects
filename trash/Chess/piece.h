#ifndef PIECE_
#define PIECE_
#include <iostream>
enum Color { empty, white, black };
enum Name { KING, QUEEN, BISHOP, KNIGHT, ROOK, PAWN, EMPTY };
class Piece
{
public:
    virtual bool move(size_t,size_t) = 0 ;
    void set_px(size_t) ;
    void set_py(size_t) ;
    void set_color(Color) ;
    Color get_color() const ;
    int get_px() const ;
    int get_py() const ;
    Name get_name() const ;
    Piece& operator=(Piece &) ;
protected:
    Color color ;
    Name name ;
    size_t m_py ;
    size_t m_px ;
};

class King : public Piece
{
public:
    King(Color) ;
    bool move(size_t x,size_t y ) override ;
private:

};

class Queen : public Piece
{
public:
    Queen(Color) ;
    bool move(size_t x,size_t y) override ;
private:

};

class Rook : public Piece
{
public:
    Rook(Color) ;
    bool move(size_t x,size_t y ) override ;
private:

};

class Bishop : public Piece
{
public:
    Bishop(Color) ;
    bool move(size_t x,size_t y) override ;
private:

};

class Pawn : public Piece
{
public:
    Pawn(Color) ;
    bool move(size_t x,size_t y) override ;
private:

};

class Knight : public Piece
{
public:
    Knight(Color) ;
    bool move(size_t x,size_t y) override ;
private:

};

class Empty : public Piece
{
public:
    Empty() ;
    bool move(size_t x,size_t y ) override {
        return false ;
    }
private:

};

#endif