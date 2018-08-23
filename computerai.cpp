#include "computerai.h"

#include <QString>
#include <vector>
#include <map>
#include <QFile>
#include <QDomDocument>
#include <QtDebug>
#include <math.h>

using namespace std;

const int BOARDSIZE = 3;
ComputerAI::ComputerAI()
{
    this->ComputerDataStructure = LoadXMLStructure("C:/Users/Chris/Documents/TicTaco/PlayerMoves.xml");

}

vector <int> ComputerAI::getRandomMove(vector<vector<int>> board){
    bool gameLoop = true;
    vector<int> temp = {0,0};

    while(gameLoop){
        int row = (rand() % BOARDSIZE); //Compute a random value for the potential move
        int col = (rand() % BOARDSIZE); //Compute a random value for the potential move

        if (board[row][col] == 0){
        //Then we have a valid move
            temp[0] = row;
            temp[1] = col;
            return temp;

        }

}
}
vector<int> ComputerAI::makeComputerMove(vector<vector<int>> board){
    //This will make the next move of the Computer AI given the
    //current data structure

    for (map<vector<vector<int>>,vector<int>>::iterator it = this->ComputerDataStructure.begin();it!=this->ComputerDataStructure.end();++it){
        //We will need to loop through the entire board to match the current board state to one
        //That is in our computer data structure

        if (it->first == board){
            //Then we have found the state the computer should be in that matches the current

           return it->second;
        }
}
    //Otherwise we assign it a random variable
    return getRandomMove(board);  //Otherwise we can return a random move as long as it is valid

}

vector<vector<int>> ComputerAI::convert_Vector(QString boardLayout){
    const int SIZE = 3; //Size of our board
    vector <vector<int> > tempHolder(SIZE,vector<int>(SIZE,0)); //Temporary vector to hold the boardlayout conversion
    //This function will take the Qstring value and convert it to a 2D array


    for (int i = 0; i < 9;i++)
    {
            //The bottom two indices will convert it to the appropriate index for the 2D vector
           int verticalIndex = i % SIZE;
           int horizontalIndex = floor(i/SIZE);
           int i_current =horizontalIndex;
           int j_current = verticalIndex;

            if (boardLayout[i] == "*"){
            tempHolder[i_current][j_current] = 0; //Then we want to assign it a value of zero since it is an empty position
            }
            else if (boardLayout[i] == "X"){
                tempHolder[i_current][j_current] = 1;
            }
            else{
                tempHolder[i_current][j_current] = 2;
            }

    }

    return tempHolder;
}
map <vector<vector<int>>, vector<int>> ComputerAI::LoadXMLStructure(QString fileType){ //We want to load the document

    QDomDocument document;
    QFile file(fileType);

    vector<vector<int>> tempVecHolder;

    document.setContent(&file);
    //Get the root element of the file
    file.close();
    map <vector<vector<int>>, vector<int> > dataStorage;
    //return dataStorage;
    //Close the file
    QDomElement geometry = document.documentElement();

    for (int i = 0; i < geometry.childNodes().size();i++){
        auto current = geometry.childNodes().item(i).toElement();

       vector<int> boardConfig;
       int row;
       int column;
        for (int j = 0; j < current.childNodes().size();j++){

            auto BCR = current.childNodes().item(j).toElement(); // WE can grab the current value orf (column row or boar)

            // No we want to append the data into the data structure we have specified above
            if (j == 0) {
                //This repressents the row
                row = BCR.attribute("name").toInt();
            }else if (j == 1){
                //This represents the column
                column = BCR.attribute("name").toInt();
            }else if (j == 2){
                tempVecHolder = convert_Vector(BCR.attribute("name"));
            }

        }
        //qDebug() << row, column;
        vector<int> temptHolder {row,column};
        dataStorage.insert(std::pair<vector<vector<int>>, vector<int> >(tempVecHolder,temptHolder));
            }
        return dataStorage;
}
