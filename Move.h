//
// Created by Mathieu on 22/05/2017.
//

#ifndef CHESS_AI_MOVE_H
#define CHESS_AI_MOVE_H


#include "Piece.h"

class Move{

private:
    int init;
    int final;
    Piece movedPiece;
    int idPieceTaken = -1;


public:
    void play();
};

#endif //CHESS_AI_MOVE_H
