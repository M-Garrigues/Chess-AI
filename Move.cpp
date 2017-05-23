//
// Created by Mathieu on 22/05/2017.
//

#include "Move.h"

int Move::getInitX() {
    return init%8;
}

int Move::getInitY() {
    return (int)(init - 1)/8 + 1;
}

int Move::getFinalX() {
    return final%8;
}

int Move::getFinalY() {
    return (int)(final - 1)/8 + 1;
}

Move::Move(int dep, int fin, Piece &newpiece) {

    init = dep;
    final = fin;
    movedPiece = &newpiece;
}

Move::Move() {

}

void Move::printMove() {

    char p;

    std::cout << (char)(init%8 + 96) << (init -1)/8 + 1 << "-" << (char)(final%8 + 96) << (final -1)/8 + 1 << std::endl;
}
