//
// Created by Mathieu on 22/05/2017.
//

#ifndef CHESS_AI_PIECE_H
#define CHESS_AI_PIECE_H

#include <vector>
#include "Move.h"
#include "Board.h"

class Move;
class Board;

enum Color{WHITE, BLACK};

class Piece{

private:

    unsigned char x;
    unsigned char y;
    std::vector<Move> listMoves;
    Color color;
    bool pinned = false;

public:

    Piece();
    Piece(Color newColor, unsigned char x, unsigned char y);

    virtual std::vector<int> getMoveCells(Board &board);
    virtual std::vector<int> getAttackCells(Board &board);

    void genMoves(std::vector<int> &listCells);

    bool isPinned();


    int getX();
    int getY();
    Color getColor();
    std::vector<Move> * getMoves();


};
#endif //CHESS_AI_PIECE_H
