#ifndef COMPUTERAI_H
#define COMPUTERAI_H

#include <QString>
#include <vector>
#include <map>
using namespace std;

class ComputerAI
{
public:
    ComputerAI();
    vector<int> makeComputerMove(vector<vector<int>> board);
    map <vector<vector<int>>, vector<int>> LoadXMLStructure(QString fileType);
    vector<vector<int>> convert_Vector(QString boardLayout);
    vector <int> getRandomMove(vector<vector<int>> board);
    //vector <int> convertBoard_Vector(int board[3][3]);
private:
    map <vector<vector<int>>, vector<int>> ComputerDataStructure; //storing the computer data structure in a temporary map variable

};

#endif // COMPUTERAI_H
