//
// Created by Mathieu on 22/05/2017.
//

#ifndef CHESS_AI_PIECE_H
#define CHESS_AI_PIECE_H

#include <vector>
#include "Move.h"
#include "Board.h"

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
    Piece(Color, unsigned char x, unsigned char y);
    std::vector<Move> genMovesb(Board board);
};
#endif //CHESS_AI_PIECE_H
