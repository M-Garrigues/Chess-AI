//
// Created by Mathieu on 22/05/2017.
//

#include <assert.h>
#include "Board.h"

Board::Board(){}

Board::Board(std::vector<Piece *> & tabPieces){
    
    for(int i = 0; i < 10; i++){
        board[i][0] = LIMIT;
        board[0][i] = LIMIT;
        board[i][9] = LIMIT;
        board[9][i] = LIMIT;
    }

    for(int i = 1; i < 9; i++){
        for(int j = 1; j < 9; j++){
            board[i][j] = EMPTY;

        }
    }

    board[2][1] = WN; board[4][1] = WK; board[6][1] = WB; board[8][1] = WR;
    board[1][2] = WP; board[3][2] = WP; board[5][2] = WP; board[7][2] = WP;
    board[2][3] = WP; board[4][3] = WP; board[6][3] = WP; board[8][3] = WP;


    board[2][8] = BN; board[4][8] = BK; board[6][8] = BB; board[8][8] = BR;
    board[1][7] = BP; board[3][7] = BP; board[5][7] = BP; board[7][7] = BP;
    board[2][6] = BP; board[4][6] = BP; board[6][6] = BP; board[8][6] = BP;

    
    
    

    whiteThreatBoard[3][1] = 1; whiteThreatBoard[5][1] = 1; whiteThreatBoard[7][1] = 1;
    whiteThreatBoard[3][2] = 1; whiteThreatBoard[4][2] = 2; whiteThreatBoard[5][2] = 2; whiteThreatBoard[7][2] = 1; whiteThreatBoard[8][2] = 1;
    whiteThreatBoard[1][3] = 1; whiteThreatBoard[2][3] = 2; whiteThreatBoard[3][3] = 1; whiteThreatBoard[4][3] = 2; whiteThreatBoard[6][3] = 2; whiteThreatBoard[8][3] = 2;
    whiteThreatBoard[1][4] = 1; whiteThreatBoard[3][4] = 2; whiteThreatBoard[5][4] = 2; whiteThreatBoard[7][4] = 2;


/*
    for(int i = 8; i >= 1; i--){
        for(int j = 1; j < 9; j++){
            std::cout << whiteThreatBoard[j][i];
        }
        std::cout << std::endl;
    }

    std::cout << std::endl;std::cout << std::endl;std::cout << std::endl;
*/


    blackThreatBoard[3][8] = 1; blackThreatBoard[5][8] = 1; blackThreatBoard[7][8] = 1;
    blackThreatBoard[3][7] = 1; blackThreatBoard[4][7] = 2; blackThreatBoard[5][7] = 2; blackThreatBoard[7][7] = 1; blackThreatBoard[8][7] = 1;
    blackThreatBoard[1][6] = 1; blackThreatBoard[2][6] = 2; blackThreatBoard[3][6] = 1; blackThreatBoard[4][6] = 2; blackThreatBoard[6][6] = 2; blackThreatBoard[8][6] = 2;
    blackThreatBoard[1][5] = 1; blackThreatBoard[3][5] = 2; blackThreatBoard[5][5] = 2; blackThreatBoard[7][5] = 2;



std::cout << tabPieces[0];


    pieces[2][1] = tabPieces[0]; pieces[4][1] = tabPieces[1]; pieces[6][1] = tabPieces[2]; pieces[8][1] = tabPieces[3];
    pieces[1][2] = tabPieces[4]; pieces[3][2] = tabPieces[5]; pieces[5][2] = tabPieces[6]; pieces[7][2] = tabPieces[7];
    pieces[2][3] = tabPieces[8]; pieces[4][3] = tabPieces[9]; pieces[6][3] = tabPieces[10]; pieces[8][3] = tabPieces[11];


    pieces[2][8] = tabPieces[12]; pieces[4][8] = tabPieces[13]; pieces[6][8] = tabPieces[14]; pieces[8][8] = tabPieces[15];
    pieces[1][7] = tabPieces[16]; pieces[3][7] = tabPieces[17]; pieces[5][7] = tabPieces[18]; pieces[7][7] = tabPieces[19];
    pieces[2][6] = tabPieces[20]; pieces[4][6] = tabPieces[21]; pieces[6][6] = tabPieces[22]; pieces[8][6] = tabPieces[23];


    xWK = 4; yWK = 1;

    xBK = 4; yBK = 8;
}



Board::Board(Board &newBoard){

    for(int i = 0; i < 10; i++){
        for(int j = 0; j < 10; j++){
            this->board[i][j] = newBoard.board[i][j];
            this->whiteThreatBoard[i][j] = newBoard.whiteThreatBoard[i][j];
            this->blackThreatBoard[i][j] = newBoard.blackThreatBoard[i][j];
            this->pieces[i][j] = newBoard.pieces[i][j];
        }
    }
}


void Board:: printBoard(){


    for(int j = 9; j > 0; j--){
        for(int i = 0; i < 10; i++){

            if(board[i][j] == LIMIT)
                std::cout << "-";
            else
                std::cout << board[i][j];
        }
        std::cout<<"\n";
    }

    std::cout << "\n\n";

    display();
}

void update(Move & move);

bool check();

bool mate();


void Board::display(){

    char displayBoard[38][53] = {

            {' ', ' ', ' ', ' ', ' ', ' ', ' ', 'A', ' ', ' ', ' ', ' ', ' ', 'B', ' ', ' ', ' ', ' ', ' ', 'C', ' ', ' ', ' ', ' ', ' ', 'D', ' ', ' ', ' ', ' ', ' ', 'E', ' ', ' ', ' ', ' ', ' ', 'F', ' ', ' ', ' ', ' ', ' ', 'G', ' ', ' ', ' ', ' ', ' ', 'H', ' ', ' ', ' '},
            {' ', ' ', ' ', ' ', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#'},
            {' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#'},
            {' ', ' ', '8', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#'},
            {' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#'},
            {' ', ' ', ' ', ' ', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#'},
            {' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#'},
            {' ', ' ', '7', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#'},
            {' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#'},
            {' ', ' ', ' ', ' ', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#'},
            {' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#'},
            {' ', ' ', '6', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#'},
            {' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#'},
            {' ', ' ', ' ', ' ', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#'},
            {' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#'},
            {' ', ' ', '5', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#'},
            {' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#'},
            {' ', ' ', ' ', ' ', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#'},
            {' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#'},
            {' ', ' ', '4', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#'},
            {' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#'},
            {' ', ' ', ' ', ' ', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#'},
            {' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#'},
            {' ', ' ', '3', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#'},
            {' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#'},
            {' ', ' ', ' ', ' ', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#'},
            {' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#'},
            {' ', ' ', '2', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#'},
            {' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#'},
            {' ', ' ', ' ', ' ', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#'},
            {' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#'},
            {' ', ' ', '1', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#'},
            {' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#'},
            {' ', ' ', ' ', ' ', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#'},


    };

    //"displayRow"...converts the standard board coordinates to display coordinates
    //i.e. the 0th row of the real board is equivalent to the 31st row of the display board just by how I've set it up
    int dR0 = 31;
    int dR1 = 27;
    int dR2 = 23;
    int dR3 = 19;
    int dR4 = 15;
    int dR5 = 11;
    int dR6 = 7;
    int dR7 = 3;

    //"displayColumn"
    int dC0 = 7;
    int dC1 = 13;
    int dC2 = 19;
    int dC3 = 25;
    int dC4 = 31;
    int dC5 = 37;
    int dC6 = 43;
    int dC7 = 49;

    int tempRow = 0;
    int tempColumn = 0;

    //updates real piece locations on the "display board"
    for(int i = 0; i < 8; i++){

        if(i == 0)
            tempRow = dR0;
        else if(i == 1)
            tempRow = dR1;
        else if(i == 2)
            tempRow = dR2;
        else if(i == 3)
            tempRow = dR3;
        else if(i == 4)
            tempRow = dR4;
        else if(i == 5)
            tempRow = dR5;
        else if(i == 6)
            tempRow = dR6;
        else
            tempRow = dR7;



        for(int j = 0; j < 8; j++){

            if(j == 0)
                tempColumn = dC0;
            else if(j == 1)
                tempColumn = dC1;
            else if(j == 2)
                tempColumn = dC2;
            else if(j == 3)
                tempColumn = dC3;
            else if(j == 4)
                tempColumn = dC4;
            else if(j == 5)
                tempColumn = dC5;
            else if(j == 6)
                tempColumn = dC6;
            else
                tempColumn = dC7;

            i++;
            j++;

            //update display board pieces to match the real board
            if(board[j][i] == 0)
                displayBoard[tempRow][tempColumn] = ' ';

            else if(board[j][i] == WP || board[j][i] == BP)
                displayBoard[tempRow][tempColumn] = 'P';

            else if(board[j][i] == WK || board[j][i] == BK)
                displayBoard[tempRow][tempColumn] = 'K';

            else if(board[j][i] == WQ || board[j][i] == BQ)
                displayBoard[tempRow][tempColumn] = 'Q';

            else if(board[j][i] == WB|| board[j][i] == BB)
                displayBoard[tempRow][tempColumn] = 'B';

            else if(board[j][i] == WN || board[j][i] == BN)
                displayBoard[tempRow][tempColumn] = 'N';

            else if(board[j][i] == WR || board[j][i] == BR)
                displayBoard[tempRow][tempColumn] = 'R';
            else
                displayBoard[tempRow][tempColumn] = ' ';

            j--;
            i--;
        }
    }




    for(int i = 0; i < 34; i++){

        std::cout<<std::endl;

        for(int j = 0; j < 53; j++){

            std::cout<<displayBoard[i][j];

        }
    }


    std::cout<<std::endl<<std::endl;

}

void Board::move(Move &move) {

    int xI = move.getInitX();
    int yI = move.getInitY();

    int xF = move.getFinalX();
    int yF = move.getFinalY();

    assert(xI >= 0 && xI <9 && yI >= 0 && yI <9 && xF >= 0 && xF <9 && yF >= 0 && yF <9);


    pieces[xF][yF] = pieces[xI][yI];
    pieces[xI][yI] = nullptr;


    board[xF][yF] = board[xI][yI];
    board[xI][yI] = 0;


    pieces[xF][yF]->setX(xF);
    pieces[xF][yF]->setY(yF);
}

Piece * Board::getPiece(int i) {
    return pieces[(i - 1)%8 + 1][(i-1)/8 + 1];
}



Board::ptr_to_arrays Board::getBoard() {
    return board ;
}

Board::ptr_to_arrays Board::getThreats(Color color) {
    if(color == BLACK)
        return whiteThreatBoard;
    else
        return blackThreatBoard;
}

int Board::posToKing(Color color, int x, int y) {

    if(color == BLACK){
        assert(x != xWK && y != yWK);

        if(x == xWK && y > yWK) return 1;
        if(x > xWK && y == yWK) return 2;
        if(x == xWK && y < yWK) return 3;
        if(x < xWK && y == yWK) return 4;
        if(x < xWK && y > yWK && x - xWK == yWK - y) return 5;
        if(x > xWK && y > yWK && x - xWK == y - yWK) return 6;
        if(x > xWK && y < yWK && x - xWK == yWK - y) return 7;
        if(x < xWK && y < yWK && x - xWK == y - yWK) return 8;
    }
    else{
        assert(x != xBK && y != yBK);

        if(x == xBK && y > yBK) return 1;
        if(x > xBK && y == yBK) return 2;
        if(x == xBK && y < yBK) return 3;
        if(x < xBK && y == yBK) return 4;
        if(x < xBK && y > yBK && xBK - x == y - yBK) return 5;
        if(x > xBK && y > yBK && x - xBK == y - yBK) return 6;
        if(x > xBK && y < yBK && x - xBK == yBK - y) return 7;
        if(x < xBK && y < yBK && x - xBK == y - yBK) return 8;
    }

    return 0;
}

void Board::updatePins(Move move) {
    updatePinsInit(move);
    updatePinsFinal();

}

void Board::updatePinsInit(Move move) { //WOULD NEED AN UPDATE TO BE EFFECTIVE FOR CLASSIC CHESS

    int cX = move.getInitX();
    int cY = move.getInitY();

    Piece * piece = move.getMovedPiece();

    int posKing = posToKing(piece->getColor(), cX, cY);

    if( posKing != 0){

        if(posKing < 5 && piece->isRook()){
            if()
        }
        else if(posKing > 4 && piece->isBishop()){

        }
    }




}
