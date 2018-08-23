#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "boardstate.h"
#include "computerai.h"

const QString COMPUTERPLAYER = "O";


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{

    ui->setupUi(this);
    this->board = new BoardState();
    this->computerPlayer = new ComputerAI();
}

MainWindow::~MainWindow()
{
    delete ui;
    delete board;
    delete computerPlayer;
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

    vector<int> move = this->computerPlayer->makeComputerMove(this->board->getBoard()); //Now We want to pass through the current board status in order to determine the move of the compute r
    this->board->setBoardMove(move[0],move[1],2);//Set the board position
    setMove_UI(move[0],move[1],COMPUTERPLAYER);
}


}
void MainWindow::setMove_UI(int i, int j,QString PlayerType){
    //This will control the flow of all data for the Computer AI
    if (i == 0 && j == 0) //Row 0 col 0
    {
        QFont font = ui->row0col0->font();
        font.setPointSize(450);
        ui->row0col0->setText(PlayerType);

}
    if (i == 0 && j == 1) //Row 0 col 0

    {
        QFont font = ui->row0col1->font();
        font.setPointSize(450);
        ui->row0col1->setText(PlayerType);
    }
    if (i == 0 && j == 2) //Row 0 col 0
    {
        QFont font = ui->row0col2->font();
        font.setPointSize(450);
        ui->row0col2->setText(PlayerType);
    }
    if (i == 1 && j == 0) //Row 0 col 0
    {
        QFont font = ui->row1col0->font();
        font.setPointSize(450);
        ui->row1col0->setText(PlayerType);
    }
    if (i == 1 && j == 1) //Row 0 col 0
    {
        QFont font = ui->row1col1->font();
        font.setPointSize(450);
        ui->row1col1->setText(PlayerType);
    }
    if (i == 1 && j == 2) //Row 0 col 0
    {
        QFont font = ui->row1col2->font();
        font.setPointSize(450);
        ui->row1col2->setText(PlayerType);
    }
    if (i == 2 && j == 0) //Row 0 col 0
    {
        QFont font = ui->row2col0->font();
        font.setPointSize(450);
        ui->row2col0->setText(PlayerType);
    }
    if (i == 2 && j == 1) //Row 0 col 0
    {
        QFont font = ui->row2col1->font();
        font.setPointSize(450);
        ui->row2col1->setText(PlayerType);
    }
    if (i == 2 && j == 2) //Row 0 col 0
    {
        QFont font = ui->row2col2->font();
        font.setPointSize(450);
        ui->row2col2->setText(PlayerType);
    }


}


void MainWindow::on_row0col1_clicked()
{

}

void MainWindow::on_row0col2_clicked()
{

}

void MainWindow::on_row1col0_clicked()
{

}

void MainWindow::on_row1col1_clicked()
{

}

void MainWindow::on_row1col0_2_clicked()
{

}

void MainWindow::on_row2col0_clicked()
{

}

void MainWindow::on_row2col1_clicked()
{

}

void MainWindow::on_row2col2_clicked()
{

}

void MainWindow::on_row1col2_clicked()
{

}
