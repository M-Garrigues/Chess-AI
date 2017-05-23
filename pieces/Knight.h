//
// Created by Mathieu on 22/05/2017.
//

#ifndef CHESS_AI_KNIGHT_H
#define CHESS_AI_KNIGHT_H


#include "../Piece.h"

class Knight : public Piece{

public:
    Knight();
    Knight(Color color, int x, int y);
};

#endif //CHESS_AI_KNIGHT_H
