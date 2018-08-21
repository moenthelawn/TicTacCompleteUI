#include "boardstate.h"
//1 corresponds player X
//2 corresponds player O
BoardState::BoardState()
{
initializeBoard(this->board);//We want to initialize the board to all zeros

}

bool BoardState::setBoardMove(int i, int j,int PlayerType){
//Returns 1 if the board move is a valid move
//Returns 0 if the board move is not a valid move
//Here we will set the board move based on an input from the user

    if (this->board[i][j] == 0){
        //Then the current board is unoccpuied
        this->board[i][j] = PlayerType;//Set the board move to the player type
        return true;

    }
    else{
        //Then this board is occupied by the current
        return false;
    }

}
void BoardState::initializeBoard(int board[3][3]){
    for (int i =0; i < 3;i++){
        for(int j =0 ; j < 3;j++){
            board[i][j] = 0;
        }
    }
}
