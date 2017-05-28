//
// Created by Mathieu on 22/05/2017.
//

#ifndef CHESS_AI_PIECE_H
#define CHESS_AI_PIECE_H

#include <vector>
#include "Board.h"
#include "Move.h"

class Board;
class Move;



class Piece{

private:

    unsigned char x;
    unsigned char y;
    std::vector<Move> listMoves;
    Color color;
    bool pinned = false;

public:

    Piece();
    ~Piece();
    Piece(Color newColor, unsigned char x, unsigned char y);

    virtual std::vector<int> getMoveCells(Board &board);
    virtual std::vector<int> getAttackCells(Board &board);

    void genMoves(Board & board);

    bool isPinned();


    int getX();
    int getY();
    Color getColor();

    void setColor(Color newColor);
    void setX(unsigned char newX);
    void setY(unsigned char newY);

    std::vector<Move> * getMoves();

    bool isRook();
    bool isBishop();


};
#endif //CHESS_AI_PIECE_H
