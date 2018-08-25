#ifndef BOARDSTATE_H
#define BOARDSTATE_H
#include <vector>
using namespace std;

class BoardState
{
public:
    BoardState();

    vector<vector<int>> initializeBoard();
    bool setBoardMove(int i, int j,int PlayerType);
    vector<vector<int>> getBoard();
    bool isWinner(unsigned int x, unsigned int y);
    unsigned int checkState(unsigned int i,unsigned int j,unsigned int playerType);
    bool checkArrayBounds(unsigned int i,unsigned int j);
    bool isDraw();

private:
    vector<vector<int>> board;
};

#endif // BOARDSTATE_H
