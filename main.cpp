#include "mainwindow.h"
#include "boardstate.h"
#include <QApplication>
#include <QtXml>
#include <QDebug>
#include <QFile>
#include <QtCore>
#include <QString>
#include <map>

#include <vector>
#include <string>
using namespace std;


int main(int argc, char *argv[])
{


    QApplication a(argc, argv);
    MainWindow w;
    w.show();





    return a.exec();
}
