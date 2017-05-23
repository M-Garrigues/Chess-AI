//
// Created by Mathieu on 22/05/2017.
//

#ifndef CHESS_AI_BOARD_H
#define CHESS_AI_BOARD_H


#include "Move.h"
#include "Piece.h"
#include "stdio.h"
#include <iostream>

class Piece;
class Move;

enum pieces{
    LIMIT = 100, EMPTY = 0,
    WP = 1, WN = 2, WB = 3, WR = 4, WQ = 5, WK = 6,
    BP = -1, BN = -2, BB = -3, BR = -4, BQ = -5, BK = -6
};



class Board{


private:
    char board [10][10];

    char whiteThreatBoard [10][10]{};

    char blackThreatBoard [10][10]{};

    Piece * pieces[10][10]{};


    int xBK, yBK, xWK, yWK; //kings positions

    void updatePins();

    void updateThreats();


public:

    Board();
    Board(Board &board);
    Board(std::vector<Piece> & tabPieces);

    void update(Move & move);

    bool check();

    bool mate();



    //board.updatePins(move);

    //board.updateThreats(move);

    //check = board.testCheck();

    void move(Move &move);


    void printBoard();

    void display();

    Piece * getPiece(int i);

    typedef char (*ptr_to_arrays)[10]; //typedefs can make things more readable with such awkward types

    ptr_to_arrays getBoard();

    ptr_to_arrays getThreats(Color color);

    int posToKing(Color color, int x, int y);
};

#endif //CHESS_AI_BOARD_H
