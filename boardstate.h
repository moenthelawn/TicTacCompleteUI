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
private:
    vector<vector<int>> board;
};

#endif // BOARDSTATE_H
