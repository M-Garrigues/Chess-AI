//
// Created by Mathieu on 22/05/2017.
//

#include "Rook.h"

Rook::Rook(Color color, int x, int y) : Piece(color, x, y){

}

std::vector<int> Rook::getMoveCells(Board &board) {

    std::vector<int> cells;
    int x = getX();
    int y = getY();
    auto bd = board.getBoard();
    Color color = getColor();


    if(isPinned()){
        int posToKing = board.posToKing(getColor(), getX(), getY());

        if( posToKing > 4) return cells; //the piece is on the king line
        else {
            int i=x ; int j =y;

            if(posToKing == 1 || posToKing == 3){ //vertical pin

                do{
                    if(x!= i || y!=j){
                        cells.push_back(i+8*(j-1));
                    }

                    j++;
                }while(bd[i][j] == 0 || (x== i && y==j)); //1st column

                if(bd[i][j] > -10 && bd[i][j] < 10){
                    if(!board.getPiece(i+8*(j-1))->getColor() == color){ //it can go on cell occupied
                        cells.push_back(i+8*(j-1));
                    }
                }

                j = y;

                do{
                    if(x!= i || y!=j){
                        cells.push_back(i+8*(j-1));
                    }

                    j--;
                }while(bd[i][j] == 0 || (x== i && y==j)); //3rd column

                if(bd[i][j] > -10 && bd[i][j] < 10){
                    if(!board.getPiece(i+8*(j-1))->getColor() == color){ //it can go on cell occupied
                        cells.push_back(i+8*(j-1));
                    }
                }
            }
            else{ //horizontal pin
                do{
                    if(x!= i || y!=j){
                        cells.push_back(i+8*(j-1));
                    }

                    i++;
                }while(bd[i][j] == 0 || (x== i && y==j)); //2nd column

                if(bd[i][j] > -10 && bd[i][j] < 10){
                    if(!board.getPiece(i+8*(j-1))->getColor() == color){ //it can go on cell occupied
                        cells.push_back(i+8*(j-1));
                    }
                }

                i= x;

                do{
                    if(x!= i || y!=j){
                        cells.push_back(i+8*(j-1));
                    }

                    i--;
                }while(bd[i][j] == 0 || (x== i && y==j)); //4th column

                if(bd[i][j] > -10 && bd[i][j] < 10){
                    if(!board.getPiece(i+8*(j-1))->getColor() == color){ //it can go on cell occupied
                        cells.push_back(i+8*(j-1));
                    }
                }
            }

            return cells;
        }

    }


    int i = x; int j = y;

    do{
        if(x!= i || y!=j){
            cells.push_back(i+8*(j-1));
        }

        j++;
    }while(bd[i][j] == 0 || (x== i && y==j)); //1st column

    if(bd[i][j] > -10 && bd[i][j] < 10){
        if(!board.getPiece(i+8*(j-1))->getColor() == color){ //it can go on cell occupied
            cells.push_back(i+8*(j-1));
        }
    }

    j = y;

    do{
        if(x!= i || y!=j){
            cells.push_back(i+8*(j-1));
        }

        j--;
    }while(bd[i][j] == 0 || (x== i && y==j)); //3rd column

    if(bd[i][j] > -10 && bd[i][j] < 10){
        if(!board.getPiece(i+8*(j-1))->getColor() == color){ //it can go on cell occupied
            cells.push_back(i+8*(j-1));
        }
    }


    j = y;

    do{
        if(x!= i || y!=j){
            cells.push_back(i+8*(j-1));
        }

        i++;
    }while(bd[i][j] == 0 || (x== i && y==j)); //3rd column

    if(bd[i][j] > -10 && bd[i][j] < 10){
        if(!board.getPiece(i+8*(j-1))->getColor() == color){ //it can go on cell occupied
            cells.push_back(i+8*(j-1));
        }
    }

    i = x;

    do{
        if(x!= i || y!=j){
            cells.push_back(i+8*(j-1));
            std::cout << "\nOUI\n";
        }

        i --;
        std::cout << i << " " << j << "  " << bd[i][j];
    }while(bd[i][j] == 0 || (x== i && y==j)); //3rd column

    if(bd[i][j] > -10 && bd[i][j] < 10){
        if(!board.getPiece(i+8*(j-1))->getColor() == color){ //it can go on cell occupied
            cells.push_back(i+8*(j-1));
        }
    }

    std::cout <<"\nDEBUG ::::: " << cells.capacity() << "\n";
    return cells;
}

std::vector<int> Rook::getAttackCells(Board &board) {
    return getMoveCells(board);
}
