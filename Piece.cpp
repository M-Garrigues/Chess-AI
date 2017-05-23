//
// Created by Mathieu on 22/05/2017.
//

#include "Piece.h"

Piece::Piece(){

}

Piece::Piece(Color newColor, unsigned char x, unsigned char y) {
    color = newColor;

    this->x = x;
    this->y = y;
}

int Piece::getX() {
    return x;
}

int Piece::getY(){
    return y;
}

Color Piece::getColor() {
    return color;
}

bool Piece::isPinned() {
    return pinned;
}

void Piece::genMoves(std::vector<int> &listCells) {

    std::vector<Move> * listMoves = getMoves();

    listMoves->clear(); //we reset the previously calculated moves

    int posInit = getX() + getY()*8;

    for(auto posFinal : listCells){
        listMoves->push_back(Move(posInit, posFinal, *this));
    }
}

std::vector<Move> * Piece::getMoves() {
    return &listMoves;
}
