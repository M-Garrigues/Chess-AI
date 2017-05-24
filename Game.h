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
    std::vector<Move> movesListWhite;
    std::vector<Move> movesListBlack;


    signed char castling;
    signed char halfMoves;
    bool check = false;

    Board board;
    std::vector<Piece *> whitePieces;
    std::vector<Piece *> blackPieces;

public:
    Game();

    void generateAllMoves(Color color);

    Board * getBoard();
    std::vector<Piece*> * getWhitePieces();
    std::vector<Piece*> * getBlackPieces();


    void play(Move move);

    std::vector<Move> *getMoves(Color param);
};

#endif //CHESS_AI_GAME_H
