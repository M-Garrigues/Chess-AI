//
// Created by Mathieu on 22/05/2017.
//

#ifndef CHESS_AI_ROOK_H
#define CHESS_AI_ROOK_H

#include "../Piece.h"

class Rook : public Piece{


public:
    Rook(Color color, int x, int y);

    std::vector<int> getMoveCells(Board &board);

    std::vector<int> getAttackCells(Board &board);
};


#endif //CHESS_AI_ROOK_H
