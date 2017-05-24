//
// Created by Mathieu on 22/05/2017.
//

#include "Knight.h"

Knight::Knight(Color color, int x, int y) : Piece(color, x, y){

}

std::vector<int> Knight::getMoveCells(Board &board) {
    std::vector<int> cells;
    int x = getX();
    int y = getY();
    auto bd = board.getBoard();
    Color color = getColor();


    if(isPinned()) return cells; //a pinned knight can't move, in any way.


    if(color == WHITE){

        if(y <= 6){

            if(bd[x-1][y+2] > -10 && bd[x-1][y+2] < 1){
                cells.push_back(x - 1 +(y+1)*8);
            }
            if(bd[x+1][y+2] > -10 && bd[x+1][y+2] < 1){
                cells.push_back(x + 1 +(y+1)*8);
            }
        }
        if(y >= 3){

            if(bd[x-1][y-2] > -10 && bd[x-1][y-2] < 1){
                cells.push_back(x - 1 +(y-3)*8);
            }
            if(bd[x+1][y-2] > -10 && bd[x+1][y-2] < 1){
                cells.push_back(x + 1 +(y-3)*8);
            }
        }
        if(x <= 6){

            if(bd[x+2][y-1] > -10 && bd[x+2][y-1] < 1){
                cells.push_back(x + 2 +(y-2)*8);
            }
            if(bd[x+2][y+1] > -10 && bd[x+2][y+1] < 1){
                cells.push_back(x + 2 +(y)*8);
            }
        }
        if(y >= 3){

            if(bd[x-2][y-1] > -10 && bd[x-2][y-1] < 1){
                cells.push_back(x - 2 +(y-2)*8);
            }
            if(bd[x-2][y+1] > -10 && bd[x-2][y+1] < 1){
                cells.push_back(x - 2 +(y)*8);
            }
        }
    }

    return cells;
}

std::vector<int> Knight::getAttackCells(Board &board) {
    return getMoveCells(board);
}
