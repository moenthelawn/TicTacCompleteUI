#include "xmldatastructure.h"
#include <map>
#include <QString>

XMLDataStructure::XMLDataStructure()
{

}
XMLDataStructure::map <QString, vector<int>> LoadXMLStructure(QString fileType){

    QDomDocument document;
    QFile file(fileType);

    document.setContent(&file);
    //Get the root element of the file
    file.close();
    map <QString, vector<int> > dataStorage;
   //return dataStorage;



    //Clos the file
    QDomElement geometry = document.documentElement();
    for (int i = 0; i < geometry.childNodes().size();i++){
        auto current = geometry.childNodes().item(i).toElement();


       QString boardConfig;
       int row;
       int column;
        for (int j = 0; j < current.childNodes().size();j++){

            auto BCR = current.childNodes().item(j).toElement(); // WE can grab the current value orf (column row or boar)

            // No we want to append the data into the data structure we have specified above
            if (j == 0) {
                //This represents the row
                row = BCR.attribute("name").toInt();
            }else if (j == 1){
                //This represents the column
                column = BCR.attribute("name").toInt();
            }else if (j == 2){
                boardConfig= BCR.attribute("name");
            }

        }
        //qDebug() << row, column;
        vector<int> temptHolder {row,column};
        //dataStorage.insert(pair<string,vector<int>>(boardConfig,temptHolder) );
        dataStorage.insert(std::pair<QString, vector<int> >(boardConfig,temptHolder));


    }
return dataStorage;
}
