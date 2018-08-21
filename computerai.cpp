#include "computerai.h"

#include <QString>
#include <vector>
#include <map>
#include <QFile>
#include <QDomDocument>

using namespace std;

ComputerAI::ComputerAI()
{
    this->ComputerDataStructure = LoadXMLStructure("C:/Users/Chris/Documents/TicTaco/PlayerMoves.xml");

}
void ComputerAI::makeComputerMove(int board[3][3]){
    //This will make the next move of the Computer AI given the
    //current data structure
    for (map<QString,vector<int>>::iterator it = this->ComputerDataStructure.begin();it!=this->ComputerDataStructure.end();++it){
        //We will need to loop through the entire board to match the current board state to one
        //That is in our computer data structure


    }
}
vector<int> ComputerAI::convert_Vector(QString boardLayout){
    const int SIZE = 9; //Size of our board
    vector<int> tempHolder; //Temporary vector to hold the boardlayout conversion

    for(int i =0;i < SIZE;i++){

        if (boardLayout[i] == "*"){
            //Then we can insert the value of 0 to our bord
            tempHolder.insert(tempHolder.end(),0);
        }
        else if (boardLayout[i] == "X"){
            //We add the value 1 corresponding to player X
            tempHolder.insert(tempHolder.end(),1);
        }
        else {
           //We add the value 2 corresponding to Player O
            tempHolder.insert(tempHolder.end(),2);
        }

    }
    return tempHolder;
}
map <vector<int>, vector<int>> ComputerAI::LoadXMLStructure(QString fileType){ //We want to load the document

    QDomDocument document;
    QFile file(fileType);

    document.setContent(&file);
    //Get the root element of the file
    file.close();
    map <vector<int>, vector<int> > dataStorage;
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
                boardConfig = convert_Vector(BCR.attribute("name"));
            }

        }
        //qDebug() << row, column;
        vector<int> temptHolder {row,column};
        dataStorage.insert(std::pair<vector<int>, vector<int> >(boardConfig,temptHolder));



            }
        return dataStorage;
        }
