//
// Created by Mathieu on 22/05/2017.
//

#include "Board.h"

Board::Board(){}

Board::Board(std::vector<Piece> & tabPieces){
    
    for(int i = 0; i < 11; i++){
        for(int j = 0; j < 11; j++){
            board[i][j] = LIMIT;
        }
    }
    board[2][1] = WN; board[4][1] = WK; board[6][1] = WB; board[8][1] = WR;
    board[1][2] = WP; board[3][2] = WP; board[5][2] = WP; board[7][2] = WP;
    board[2][3] = WP; board[4][3] = WP; board[6][3] = WP; board[8][3] = WP;


    board[2][8] = BN; board[4][8] = BK; board[6][8] = BB; board[8][8] = BR;
    board[1][7] = BP; board[3][7] = BP; board[5][7] = BP; board[7][7] = BP;
    board[2][6] = BP; board[4][6] = BP; board[6][6] = BP; board[8][6] = BP;

    
    
    

    whiteThreatBoard[3][1] = 1; whiteThreatBoard[5][1] = 1; whiteThreatBoard[7][1] = 1;
    whiteThreatBoard[3][2] = 1; whiteThreatBoard[4][2] = 2; whiteThreatBoard[5][2] = 2; whiteThreatBoard[8][2] = 1; whiteThreatBoard[8][2] = 1;
    whiteThreatBoard[1][3] = 1; whiteThreatBoard[2][3] = 2; whiteThreatBoard[3][3] = 1; whiteThreatBoard[4][3] = 2; whiteThreatBoard[6][3] = 2; whiteThreatBoard[8][3] = 2;
    whiteThreatBoard[1][4] = 1; whiteThreatBoard[3][4] = 2; whiteThreatBoard[7][4] = 2; whiteThreatBoard[7][4] = 2;

    

    blackThreatBoard[3][8] = 1; blackThreatBoard[5][8] = 1; blackThreatBoard[7][8] = 1;
    blackThreatBoard[3][7] = 1; blackThreatBoard[4][7] = 2; blackThreatBoard[5][7] = 2; blackThreatBoard[8][7] = 1; blackThreatBoard[8][7] = 1;
    blackThreatBoard[1][6] = 1; blackThreatBoard[2][6] = 2; blackThreatBoard[3][6] = 1; blackThreatBoard[4][6] = 2; blackThreatBoard[6][6] = 2; blackThreatBoard[8][6] = 2;
    blackThreatBoard[1][5] = 1; blackThreatBoard[3][5] = 2; blackThreatBoard[7][5] = 2; blackThreatBoard[7][5] = 2;




    pieces[2][1] = &tabPieces[0]; pieces[4][1] = &tabPieces[1]; pieces[6][1] = &tabPieces[2]; pieces[8][1] = &tabPieces[3];
    pieces[1][2] = &tabPieces[4]; pieces[3][2] = &tabPieces[5]; pieces[5][2] = &tabPieces[6]; pieces[7][2] = &tabPieces[7];
    pieces[2][3] = &tabPieces[8]; pieces[4][3] = &tabPieces[9]; pieces[6][3] = &tabPieces[10]; pieces[8][3] = &tabPieces[11];


    pieces[2][8] = &tabPieces[12]; pieces[4][8] = &tabPieces[13]; pieces[6][8] = &tabPieces[14]; pieces[8][8] = &tabPieces[15];
    pieces[1][7] = &tabPieces[16]; pieces[3][7] = &tabPieces[17]; pieces[5][7] = &tabPieces[18]; pieces[7][7] = &tabPieces[19];
    pieces[2][6] = &tabPieces[20]; pieces[4][6] = &tabPieces[21]; pieces[6][6] = &tabPieces[22]; pieces[8][6] = &tabPieces[23];
}



Board::Board(Board newBoard){

    for(int i = 0; i < 11; i++){
        for(int j = 0; j < 11; j++){
            this->board[i][j] = newBoard.board[i][j];
            this->whiteThreatBoard[i][j] = newBoard.whiteThreatBoard[i][j];
            this->blackThreatBoard[i][j] = newBoard.blackThreatBoard[i][j];
            this->pieces[i][j] = newBoard.pieces[i][j];
        }
    }
}

void update(Move & move);

bool check();

bool mate();

