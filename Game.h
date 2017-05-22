//
// Created by Mathieu on 22/05/2017.
//

#ifndef CHESS_AI_GAME_H
#define CHESS_AI_GAME_H


#include "Piece.h"
#include "Move.h"
#include "Board.h"

class Game{

private:
    int turn;
    Color activeColor;
    std::vector<Move> movesList;
    signed char castling;
    signed char halfMoves;

    Board board;
    std::vector<Piece> pieces;

};

#endif //CHESS_AI_GAME_H
