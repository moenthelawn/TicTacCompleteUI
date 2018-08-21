#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "boardstate.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{

    ui->setupUi(this);
    this->board = new BoardState();
}

MainWindow::~MainWindow()
{
    delete ui;
    delete board;
}

void MainWindow::on_checkBox_stateChanged(int arg1)
{

}

void MainWindow::on_row0col0_clicked()
{
    qDebug("Test");
if(this->board->setBoardMove(0,0,1) == true){
    QFont font = ui->row0col0->font();
    font.setPointSize(450);
    ui->row0col0->setText("X");
}
//computerMove(this->board->getCurrentBoard()) //Now We want to pass through the current board status in order to determine the move of the compute r

}


