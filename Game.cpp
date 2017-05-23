//
// Created by Mathieu on 22/05/2017.
//

#include "Game.h"
#include "pieces/Knight.h"
#include "pieces/King.h"
#include "pieces/Bishop.h"
#include "pieces/Rook.h"
#include "pieces/Pawn.h"

Game::Game() {

    turn = 1;

    activeColor = WHITE;

    signed char castling = 3; //both sides have castling enabled. 2 is only white, 1 is only black, 0 is none.
    signed char halfMoves = 0;


    
    //adding white pieces
    whitePieces.push_back(Knight(WHITE, 2, 1));
    whitePieces.push_back(King(WHITE, 4, 1));
    whitePieces.push_back(Bishop(WHITE, 6, 1));
    whitePieces.push_back(Rook(WHITE, 8, 1));

    whitePieces.push_back(Pawn(WHITE, 1, 2));
    whitePieces.push_back(Pawn(WHITE, 3, 2));
    whitePieces.push_back(Pawn(WHITE, 5, 2));
    whitePieces.push_back(Pawn(WHITE, 7, 2));

    whitePieces.push_back(Pawn(WHITE, 2, 3));
    whitePieces.push_back(Pawn(WHITE, 4, 3));
    whitePieces.push_back(Pawn(WHITE, 6, 3));
    whitePieces.push_back(Pawn(WHITE, 8, 3));
    
    
    //adding black pieces
    blackPieces.push_back(Knight(BLACK, 2, 8));
    blackPieces.push_back(King(BLACK, 4, 8));
    blackPieces.push_back(Bishop(BLACK, 6, 8));
    blackPieces.push_back(Rook(BLACK, 8, 8));

    blackPieces.push_back(Pawn(BLACK, 1, 7));
    blackPieces.push_back(Pawn(BLACK, 3, 7));
    blackPieces.push_back(Pawn(BLACK, 5, 7));
    blackPieces.push_back(Pawn(BLACK, 7, 7));

    blackPieces.push_back(Pawn(BLACK, 2, 6));
    blackPieces.push_back(Pawn(BLACK, 4, 6));
    blackPieces.push_back(Pawn(BLACK, 6, 6));
    blackPieces.push_back(Pawn(BLACK, 8, 6));


    std::vector<Piece> allPieces = whitePieces;

    allPieces.insert( allPieces.end(), blackPieces.begin(), blackPieces.end() );

    board = Board(allPieces);
}

Board Game::getBoard() {
    return board;
}

std::vector<Piece> *Game::getWhitePieces() {
    return &whitePieces;
}

std::vector<Piece> *Game::getBlackPieces() {
    return &blackPieces;
}




void Game::play(Move move) {

    //board.updatePins(move);

    //board.updateThreats(move);

    //check = board.testCheck();

    board.move(move);

    /*if(check){
        if(board.checkMate() || board.staleMate()){
            break();
        }
    }*/

    if(activeColor == BLACK){
        activeColor = WHITE;
        turn++;
    }
    else
        activeColor = BLACK;

    //COUNT HALFMOVES;
}
