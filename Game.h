//
// Created by Mathieu on 22/05/2017.
//

#ifndef CHESS_AI_GAME_H
#define CHESS_AI_GAME_H


#include "Board.h"

class Piece;
class Move;
class Board;



class Game{

private:
    int turn;
    Color activeColor;
    std::vector<Move> movesList;
    signed char castling;
    signed char halfMoves;
    bool check = false;

    Board board;
    std::vector<Piece *> whitePieces;
    std::vector<Piece *> blackPieces;

public:
    Game();

    Board * getBoard();
    std::vector<Piece*> * getWhitePieces();
    std::vector<Piece*> * getBlackPieces();

    void play(Move move);

};

#endif //CHESS_AI_GAME_H
