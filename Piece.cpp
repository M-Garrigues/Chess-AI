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

void Piece::genMoves(Board &board) {

    std::vector<Move> * listMoves = getMoves();

    //std::cout << "\nCECI EST UN TEST \n";
    listMoves->clear(); //we reset the previously calculated moves

    int posInit = getX() + (getY()-1)*8;
    //std::cout << "\nCECI EST UN aoizdhazodha\n";
    for(auto posFinal : this->getMoveCells(board)){


       // std::cout << "\nBONJOUR : " << posFinal << " \n";
        Move temp = Move(posInit, posFinal, this);
        listMoves->push_back(temp);
    }
}

std::vector<Move> * Piece::getMoves() {
    return &listMoves;
}

Piece::~Piece() {
    x = 0;
    y = 0;
}

std::vector<int> Piece::getMoveCells(Board &board) {
    return std::vector<int>();
}

std::vector<int> Piece::getAttackCells(Board &board) {
    return std::vector<int>();
}

void Piece::setColor(Color newColor) {
    this->color = newColor;
}

void Piece::setX(unsigned char newX) {
    this->x = newX;
}

void Piece::setY(unsigned char newY) {
    this->y = newY;
}
