//
// Created by Mathieu on 22/05/2017.
//

#ifndef CHESS_AI_PAWN_H
#define CHESS_AI_PAWN_H


#include "../Piece.h"

class Pawn : public Piece{

public:
    Pawn(Color color, int x, int y);

    std::vector<int> getMoveCells(Board &board);

    std::vector<int> getAttackCells(Board &board);
};

#endif //CHESS_AI_PAWN_H
