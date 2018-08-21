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
    void makeComputerMove(int board[3][3]);
    map <vector<int>, vector<int>> LoadXMLStructure(QString fileType);
    vector<int> convert_Vector(QString boardLayout);
private:
    map <vector<int>, vector<int>> ComputerDataStructure; //storing the computer data structure in a temporary map variable

};

#endif // COMPUTERAI_H
