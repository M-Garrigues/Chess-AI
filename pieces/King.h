//
// Created by Mathieu on 22/05/2017.
//

#ifndef CHESS_AI_KING_H
#define CHESS_AI_KING_H

#include "../Piece.h"

class King : public Piece{

public:
    King(Color color, int x, int y);

    std::vector<int> getMoveCells(Board &board);

    std::vector<int> getAttackCells(Board &board);
};

#endif //CHESS_AI_KING_H
