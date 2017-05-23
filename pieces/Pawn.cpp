//
// Created by Mathieu on 22/05/2017.
//

#include "Pawn.h"

Pawn::Pawn(Color color, int x, int y) : Piece(color, x, y){

}

std::vector<int> Pawn::getMoveCells(Board &board) {


    std::vector<int> cells;
    int x = getX();
    int y = getY();
    auto bd = board.getBoard();
    Color color = getColor();

    if(isPinned()) { //the pawn is pinned, the move generation is different.

        int bpts = board.posToKing(getColor(), getX(), getY());

        if (bpts > 4)//the pawn is pinned on the king diag
        {
            if (color == WHITE) {
                if (bpts == 5 && bd[x - 1][y + 1] > -10 &&
                    bd[x - 1][y + 1] < 0) { //the pawn is pined by a piece right on a diagonal cell.
                    cells.push_back(x - 1 + (y) * 8);
                } else if (bpts == 6 && bd[x + 1][y + 1] > -10 && bd[x - 1][y + 1] < 0) {
                    cells.push_back(x + 1 + (y) * 8);
                }
            } else {
                if (bpts == 5 && bd[x - 1][y - 1] > 0 &&
                    bd[x - 1][y - 1] < 10) { //the pawn is pined by a piece right on a diagonal cell.
                    cells.push_back(x - 1 + (y-2) * 8);
                } else if (bpts == 6 && bd[x + 1][y - 1] > 0 && bd[x - 1][y - 1] < 10) {
                    cells.push_back(x + 1 + (y-2) * 8);
                }
            }

            return cells;
        }

    }


    if(color == WHITE){
        if(bd[x][y+1] == 0){
            cells.push_back(x+(y)*8);
        }
        if(bd[x+1][y+1] > -10 && bd[x+1][y+1] < 0){
            cells.push_back(x+1+(y)*8);
        }
        if(bd[x-1][y+1] > -10 && bd[x-1][y+1] < 0){
            cells.push_back(x-1+(y)*8);
        }
        if(bd[x][y+2] == 0 && y == 2){
            cells.push_back(x+(y+1)*8);
        }
    }
    else{
        if(bd[x][y-1] == 0){
            cells.push_back(x+(y-2)*8);
        }
        if(bd[x+1][y-1] > 0 && bd[x+1][y-1] < 10){
            cells.push_back(x+1+(y-2)*8);
        }
        if(bd[x-1][y-1] > 0 && bd[x-1][y-1] < 10){
            cells.push_back(x-1+(y-2)*8);
        }
        if(bd[x][y-2] == 0 && y == 7){
            cells.push_back(x+(y-3)*8);
        }
    }

    return cells;
}

std::vector<int> Pawn::getAttackCells(Board &board) {
    std::vector<int> cells;
    int x = getX();
    int y = getY();
    auto bd = board.getBoard();
    Color color = getColor();


    if(isPinned() && board.posToKing(getColor(), getX(), getY()) > 4) //the pawn is pinned on the king diag
        return cells;



    if(color == WHITE){
        if(bd[x+1][y+1] > -10 && bd[x+1][y+1] < 0){
            cells.push_back(x+1+(y)*8);
        }
        if(bd[x-1][y+1] > -10 && bd[x-1][y+1] < 0){
            cells.push_back(x-1+(y)*8);
        }
    }
    else{
        if(bd[x+1][y-1] > 0 && bd[x+1][y-1] < 10){
            cells.push_back(x+1+(y-2)*8);
        }
        if(bd[x-1][y-1] > 0 && bd[x-1][y-1] < 10){
            cells.push_back(x-1+(y-2)*8);
        }
    }

    return cells;
}


