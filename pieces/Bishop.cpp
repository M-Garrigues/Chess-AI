//
// Created by Mathieu on 22/05/2017.
//

#include "Bishop.h"

Bishop::Bishop(Color newColor, int x, int y){
    setColor(newColor);
    setX(x);
    setY(y);
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
                    if(x!= i || y!=j){
                        cells.push_back(i+8*(j-1));
                    }
                    i++;j--;
                }while(bd[i][j] == 0 || (x== i && y==j)); //2nd diagonal

                if(bd[i][j] > -10 && bd[i][j] < 10){
                    if(!board.getPiece(i+8*(j-1))->getColor() == getColor()){ //it can go on cell occupied
                        cells.push_back(i+8*(j-1));
                    }
                }

                i=x; j = y;

                do{
                    if(x!= i || y!=j){
                        cells.push_back(i+8*(j-1));
                    }
                    i--;j++;
                }while(bd[i][j] == 0 || (x== i && y==j)); //4th diagonal

                if(bd[i][j] > -10 && bd[i][j] < 10){
                    if(!board.getPiece(i+8*(j-1))->getColor() == getColor()){ //it can go on cell occupied
                        cells.push_back(i+8*(j-1));
                    }
                }
            } else{ //1st and 3rd diag

                int i=x; int j = y;


                do{
                    if(x!= i || y!=j){
                        cells.push_back(i+8*(j-1));
                    }
                    i++;j++;
                }while(bd[i][j] == 0 || (x== i && y==j)); //1st diagonal

                if(bd[i][j] > -10 && bd[i][j] < 10){
                    if(!board.getPiece(i+8*(j-1))->getColor() == getColor()){ //it can go on cell occupied
                        cells.push_back(i+8*(j-1));
                    }
                }

                i=x; j = y;

                do{
                    if(x!= i || y!=j){
                        cells.push_back(i+8*(j-1));
                    }
                    i--;j--;
                }while(bd[i][j] == 0 || (x== i && y==j)); //3rd diagonal

                if(bd[i][j] > -10 && bd[i][j] < 10){
                    if(!board.getPiece(i+8*(j-1))->getColor() == getColor()){ //it can go on cell occupied
                        cells.push_back(i+8*(j-1));
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
        if(x!= i || y!=j){
            cells.push_back(i+8*(j-1));
        }
        i++;j++;
    }while(bd[i][j] == 0 || (x== i && y==j)); //1st diagonal



    if(bd[i][j] > -10 && bd[i][j] < 10){
        if(!board.getPiece(i+8*(j-1))->getColor() == getColor()){ //it can go on cell occupied
           cells.push_back(i+8*(j-1));
        }
    }


    i=x; j = y;


    do{
        if(x!= i || y!=j){
            cells.push_back(i+8*(j-1));
        }
        i++;j--;
    }while(bd[i][j] == 0 || (x== i && y==j)); //2nd diagonal

    if(bd[i][j] > -10 && bd[i][j] < 10){
        if(!board.getPiece(i+8*(j-1))->getColor() == getColor()){ //it can go on cell occupied
            cells.push_back(i+8*(j-1));
        }
    }

    i=x; j = y;


    do{
        if(x!= i || y!=j){
            cells.push_back(i+8*(j-1));
        }
        i--;j++;

    }while(bd[i][j] == 0 || (x== i && y==j)); //4th diagonal

    if(bd[i][j] > -10 && bd[i][j] < 10){

        if(!board.getPiece(i+8*(j-1))->getColor() == getColor()){ //it can go on cell occupied
            cells.push_back(i+8*(j-1));
        }
    }

    i=x; j = y;


    do{
        if(x!= i || y!=j){
            cells.push_back(i+8*(j-1));
        }
        i--;j--;
    }while(bd[i][j] == 0 || (x== i && y==j)); //3rd diagonal

    if(bd[i][j] > -10 && bd[i][j] < 10){
        if(!board.getPiece(i+8*(j-1))->getColor() == getColor()){ //it can go on cell occupied
            cells.push_back(i+8*(j-1)); //if it's the opposite color, it can go on it (and capture);
        }
    }
    return cells;
}

std::vector<int> Bishop::getAttackCells(Board &board) {
    return Bishop::getMoveCells(board);
}

