//
// Created by Mathieu on 22/05/2017.
//

#include "Bishop.h"

Bishop::Bishop(Color color, int x, int y) : Piece(color, x, y){

}

std::vector<int> Bishop::getMoveCells(Board &board) {

    std::vector<int> cells;

    if(isPinned()){
        int posToKing = board.posToKing(getColor(), getX(), getY());
        if( posToKing < 5) return cells; //the piece is on the king line
        else{

            int x = getX();
            int y = getY();
            auto bd = board.getBoard();

            if(posToKing == 5 || posToKing == 7){//2nd and 4th diagonal

                int i=x; int j = y;


                do{
                    if(x!= i && y!=j){
                        cells.push_back(i + 8*j);
                    }
                    i++;j--;
                }while(bd[i][j] == 0); //2nd diagonal

                if(bd[i][j] > -10 && bd[i][j] < 10){
                    if(!board.getPiece(i + 8j)->getColor() == getColor()){ //it can go on cell occupied
                        cells.push_back(i +8j);
                    }
                }

                i=x; j = y;

                do{
                    if(x!= i && y!=j){
                        cells.push_back(i + 8*j);
                    }
                    i--;j++;
                }while(bd[i][j] == 0); //4th diagonal

                if(bd[i][j] > -10 && bd[i][j] < 10){
                    if(!board.getPiece(i + 8j)->getColor() == getColor()){ //it can go on cell occupied
                        cells.push_back(i +8j);
                    }
                }
            } else{ //1st and 3rd diag

                int i=x; int j = y;


                do{
                    if(x!= i && y!=j){
                        cells.push_back(i + 8*j);
                    }
                    i++;j++;
                }while(bd[i][j] == 0); //1st diagonal

                if(bd[i][j] > -10 && bd[i][j] < 10){
                    if(!board.getPiece(i + 8j)->getColor() == getColor()){ //it can go on cell occupied
                        cells.push_back(i +8j);
                    }
                }

                i=x; j = y;

                do{
                    if(x!= i && y!=j){
                        cells.push_back(i + 8*j);
                    }
                    i--;j--;
                }while(bd[i][j] == 0); //3rd diagonal

                if(bd[i][j] > -10 && bd[i][j] < 10){
                    if(!board.getPiece(i + 8j)->getColor() == getColor()){ //it can go on cell occupied
                        cells.push_back(i +8j);
                    }
                }
            }


            return cells;
        }
    }

    int x = getX();
    int y = getY();
    auto bd = board.getBoard();

    int i=x; int j = y;

    do{
        if(x!= i && y!=j){
            cells.push_back(i + 8*j);
        }
        i++;j++;
    }while(bd[i][j] == 0); //1st diagonal

    if(bd[i][j] > -10 && bd[i][j] < 10){
        if(!board.getPiece(i + 8j)->getColor() == getColor()){ //it can go on cell occupied
           cells.push_back(i +8j);
        }
    }

    i=x; j = y;


    do{
        if(x!= i && y!=j){
            cells.push_back(i + 8*j);
        }
        i++;j--;
    }while(bd[i][j] == 0); //2nd diagonal

    if(bd[i][j] > -10 && bd[i][j] < 10){
        if(!board.getPiece(i + 8j)->getColor() == getColor()){ //it can go on cell occupied
            cells.push_back(i +8j);
        }
    }

    i=x; j = y;


    do{
        if(x!= i && y!=j){
            cells.push_back(i + 8*j);
        }
        i--;j++;
    }while(bd[i][j] == 0); //4th diagonal

    if(bd[i][j] > -10 && bd[i][j] < 10){
        if(!board.getPiece(i + 8j)->getColor() == getColor()){ //it can go on cell occupied
            cells.push_back(i +8j);
        }
    }

    i=x; j = y;


    do{
        if(x!= i && y!=j){
            cells.push_back(i + 8*j);
        }
        i--;j--;
    }while(bd[i][j] == 0); //3rd diagonal

    if(bd[i][j] > -10 && bd[i][j] < 10){
        if(!board.getPiece(i + 8j)->getColor() == getColor()){ //it can go on cell occupied
            cells.push_back(i +8j); //if it's the opposite color, it can go on it (and capture);
        }
    }

    return cells;
}

std::vector<int> Bishop::getAttackCells(Board &board) {
    return Piece::getMoveCells(board);
}


