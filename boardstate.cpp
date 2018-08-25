#include "boardstate.h"
#include <vector>
#include <QDebug>
using namespace std;
//1 corresponds player X
//2 corresponds player O

const unsigned int BOARDSIZE = 3;
const int WINNINGSEQUENCE = 3; //Here we are specifying what the winning sequence would be
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


bool BoardState::isDraw(){
    //This function will loop through the board and check to see if there are any
    //possible moves left to be done
    for (unsigned int i =0; i < BOARDSIZE;i++){
        for (unsigned int j =0 ; j < BOARDSIZE;j++){
            if (board[i][j] == 0){
                //Then we have moves that can still be done and thus we return false
                return false ;
            }
        }
    }
    return true;
}
bool BoardState::checkArrayBounds(unsigned int i,unsigned int j){
    //given the upper values we need to check if there
    //is an exceeding of the current bounds

    //Based on the current positio


}
bool BoardState::isWinner(unsigned int x, unsigned int y){
    //We will need to check if
    /*
     * Horizontal (left and right)
     * Vertical (up and down)
     * Diagonal (up and left)
     * Diagonal (up and right)
     * Diagonal (down and left)
     * Diagonal (down and right)
     */


    //check if previous move caused a win on vertical line
    if (board[0][y] == board[1][y] && board[1][y] == board[2][y])
        return true;

    //check if previous move caused a win on horizontal line
    if (board[x][0] == board[x][1] && board[x][1]== board[x][2])
        return true;

    //check if previous move was on the main diagonal and caused a win
    if (x == y && board[0][0] == board[1][1] && board[1][1] == board [2][2])
        return true;

    //check if previous move was on the secondary diagonal and caused a win
    if ((x + y) == 2 && board[0][2] == board[1][1] && board[1][1] == board [2][0])
        return true;

    return false;

}
void BoardState::PrintBoard(){
    //This function will print the board out for the sake of debuggin purposes
    for(unsigned int i =0; i < BOARDSIZE;i++)
    {
        for(unsigned int j =0;j < BOARDSIZE;j++){
            qDebug() << board[i][j];


        }
        qDebug() << " "<<endl;
    }

}

//We pass in the previous move and check to see if each branch of it corresponds to a win
unsigned int BoardState::checkState(unsigned int i,unsigned int j,unsigned int playerType){
    /*
     * Based on the current structure of the board, we can check
     * to see if there is either a
     * 1. Winner
     * 2. There are no more valid moves left...In such a case,it makes sense to restart
     * the board
*/

    if (isWinner(i,j)){
        //We need to reset the board
        this->board = initializeBoard();
        return playerType;
    }
    else if (isDraw()){
        this->board = initializeBoard();
        return 3; //We return 3 which corrsponds to the value of a draw
    }
    else{
        return 0;//Other wise we retur 0 since there are still valid moves left to be done
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
