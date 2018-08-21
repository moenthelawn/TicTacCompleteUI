#ifndef BOARDSTATE_H
#define BOARDSTATE_H


class BoardState
{
public:
    BoardState();
    int getCurrentBoard();
    void initializeBoard(int board[3][3]);
    bool setBoardMove(int i, int j,int PlayerType);
private:
    int board[3][3];
};

#endif // BOARDSTATE_H
