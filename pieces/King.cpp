//
// Created by Mathieu on 22/05/2017.
//

#include "King.h"

King::King(Color color, int x, int y) : Piece(color, x, y){

}


std::vector<int> King::getMoveCells(Board &board) {

    std::vector<int> cells;
    int x = getX();
    int y = getY();
    auto bd = board.getBoard();
    auto threats = board.getThreats(getColor());


    for(int i = x-1; i < x+2;i++){
        for(int j = y-1; j < y+2; j++){
            
            if(i!=x && j != y){
                
                if(bd[i][j] == 0){
                    if(threats[i][j] == 0){
                        cells.push_back((i) + (j)*8);
                    }
                }else if(bd[i][j] > -10 && bd[i][j] < 10){

                    if(threats[i][j] == 0 && !board.getPiece((i) +(j)*8)->getColor() == getColor()){
                        cells.push_back((i) + (j)*8);
                    }
                }
            }
        }
    }
}


std::vector<int> King::getAttackCells(Board &board) {
    return Piece::getMoveCells(board);
}


