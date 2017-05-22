//
// Created by Mathieu on 22/05/2017.
//

#ifndef CHESS_AI_BOARD_H
#define CHESS_AI_BOARD_H


#include "Move.h"

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


    void updatePins();

    void updateThreats();


public:

    Board();
    Board(Board board);
    Board::Board(std::vector<Piece> & tabPieces);

    void update(Move & move);

    bool check();

    bool mate();
};

#endif //CHESS_AI_BOARD_H
