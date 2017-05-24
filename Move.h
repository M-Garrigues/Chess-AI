//
// Created by Mathieu on 22/05/2017.
//

#ifndef CHESS_AI_MOVE_H
#define CHESS_AI_MOVE_H

enum Color{WHITE, BLACK};


#include "Piece.h"

class Piece;

class Move{

private:
    int init;
    int final;
    Piece * movedPiece;
    int idPieceTaken = -1;


public:

    Move();
    Move(int dep, int fin, Piece * piece);

    int getInitX();
    int getInitY();

    int getFinalX();
    int getFinalY();

    Piece * getMovedPiece();

    void printMove();

};

#endif //CHESS_AI_MOVE_H
