//
// Created by Mathieu on 22/05/2017.
//

#include <iostream>
#include "Move.h"

int Move::getInitX() {
    return (init - 1)%8 + 1;
}

int Move::getInitY() {
    return (int)(init - 1)/8 + 1;
}

int Move::getFinalX() {
    return (final - 1)%8 + 1;
}

int Move::getFinalY() {
    return (int)(final - 1)/8 + 1;
}

Move::Move(int dep, int fin, Piece * newpiece) {

    init = dep;
    final = fin;
    movedPiece = newpiece;
}

Move::Move() {

}

void Move::printMove() {

    char p =(char)(((init - 1)%8 +1) +96);

    char f =(char)(((final - 1)%8 + 1) + 96);

    std::cout << p << (init -1)/8 + 1<< "-" << f << (final -1)/8 +1<< std::endl;
}

Piece *Move::getMovedPiece() {
    return movedPiece;
}
