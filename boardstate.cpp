#include "boardstate.h"
#include <vector>
using namespace std;
//1 corresponds player X
//2 corresponds player O
BoardState::BoardState()
{

    this->board =initializeBoard();//We want to initialize the board to all zeros
}
vector<vector<int>> BoardState::getBoard(){
    return this->board;
}
bool BoardState::setBoardMove(int i, int j,int PlayerType){
//Returns 1 if the board move is a valid move
//Returns 0 if the board move is not a valid move
//Here we will set the board move based on an input from the user

    if (this->board[i][j] == 0){
        //Then the current board is unoccpuied
        this->board[i][j]= PlayerType;//Set the board move to the player type
        return true;
    }
    else{
        //Then this board is occupied by the current
        return false;
    }
}
vector<vector<int>> BoardState::initializeBoard(){
    const int BOARDSIZE = 3;
    vector<vector<int>> board;

    for (int i =0; i < BOARDSIZE;i++){
        vector <int> tempHolder;
        for(int j =0 ; j < BOARDSIZE;j++){

               tempHolder.push_back(0);
        }
        board.push_back(tempHolder);
    }
    return board;
}
