#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "boardstate.h"
#include "computerai.h"
#include "QDebug"

const QString COMPUTERPLAYER = "O";
const QString HUMANPLAYER = "X";
const unsigned int X = 1;
const unsigned int O = 2;

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

    unsigned int currentBoardState;
    unsigned int currentBoardState_Computer;

    const int IPOSITION = 0;
    const int JPOSITION = 0;
    if(this->board->setBoardMove(IPOSITION,JPOSITION,1) == true){
        setMove_UI(IPOSITION,IPOSITION,HUMANPLAYER);
        currentBoardState = this->board->checkState(IPOSITION,JPOSITION,X);
        if (currentBoardState != 0){
            redrawBoard();
        }

    }
    vector<int> move = this->computerPlayer->makeComputerMove(this->board->getBoard()); //Now We want to pass through the current board status in order to determine the move of the compute r
    this->board->setBoardMove(move[0],move[1],O);//Set the board position

    setMove_UI(move[0],move[1],COMPUTERPLAYER);
    this->board->PrintBoard(); //Printing out for debugging purposes
    //AlsoF we want to check if there are no other moves in the game
    currentBoardState_Computer = this->board->checkState(move[0],move[1],O);
    if (currentBoardState_Computer != 0){
        redrawBoard();
    }


    qDebug() << "Board State from human player: " << currentBoardState << "Board state from computer " << currentBoardState_Computer;


}
void MainWindow::setMove_UI(int i, int j,QString PlayerType){
    //This will control the flow of all data for the Computer AI
    if (i == 0 && j == 0) //Row 0 col 0
    {
        QFont font = ui->row0col0->font();
        font.setPointSize(450);
        ui->row0col0->setText(PlayerType);

    }
    if (i == 0 && j == 1) //Row 0 col 1

    {
        QFont font = ui->row0col1->font();
        font.setPointSize(450);
        ui->row0col1->setText(PlayerType);
    }
    if (i == 0 && j == 2) //Row 0 col 2
    {
        QFont font = ui->row0col2->font();
        font.setPointSize(450);
        ui->row0col2->setText(PlayerType);
    }
    if (i == 1 && j == 0) //Row 1 col 0
    {
        QFont font = ui->row1col0->font();
        font.setPointSize(450);
        ui->row1col0->setText(PlayerType);
    }
    if (i == 1 && j == 1) //Row 1 col 1
    {
        QFont font = ui->row1col1->font();
        font.setPointSize(450);
        ui->row1col1->setText(PlayerType);
    }
    if (i == 1 && j == 2) //Row 1 col 2
    {
        QFont font = ui->row1col2->font();
        font.setPointSize(450);
        ui->row1col2->setText(PlayerType);
    }
    if (i == 2 && j == 0) //Row 2 col 0
    {
        QFont font = ui->row2col0->font();
        font.setPointSize(450);
        ui->row2col0->setText(PlayerType);
    }
    if (i == 2 && j == 1) //Row 2 col 1
    {
        QFont font = ui->row2col1->font();
        font.setPointSize(450);
        ui->row2col1->setText(PlayerType);
    }
    if (i == 2 && j == 2) //Row 2 col 2
    {
        QFont font = ui->row2col2->font();
        font.setPointSize(450);
        ui->row2col2->setText(PlayerType);
    }


}


void MainWindow::on_row0col1_clicked()
{
    unsigned int currentBoardState;
    unsigned int currentBoardState_Computer;

    const int IPOSITION = 0;
    const int JPOSITION = 1;
    if(this->board->setBoardMove(IPOSITION,JPOSITION,1) == true){
        setMove_UI(IPOSITION,JPOSITION,HUMANPLAYER);
        currentBoardState = this->board->checkState(IPOSITION,JPOSITION,X);
        if (currentBoardState != 0){
            redrawBoard();
        }

    }
    vector<int> move = this->computerPlayer->makeComputerMove(this->board->getBoard()); //Now We want to pass through the current board status in order to determine the move of the compute r
    this->board->setBoardMove(move[0],move[1],O);//Set the board position

    setMove_UI(move[0],move[1],COMPUTERPLAYER);
    this->board->PrintBoard(); //Printing out for debugging purposes
    //AlsoF we want to check if there are no other moves in the game
    currentBoardState_Computer = this->board->checkState(move[0],move[1],O);
    if (currentBoardState_Computer != 0){
        redrawBoard();
    }


    qDebug() << "Board State from human player: " << currentBoardState << "Board state from computer " << currentBoardState_Computer;

}

void MainWindow::on_row0col2_clicked()
{
    unsigned int currentBoardState;
    unsigned int currentBoardState_Computer;

    const int IPOSITION = 0;
    const int JPOSITION = 2;
    if(this->board->setBoardMove(IPOSITION,JPOSITION,1) == true){
        setMove_UI(IPOSITION,JPOSITION,HUMANPLAYER);
        currentBoardState = this->board->checkState(IPOSITION,JPOSITION,X);
        if (currentBoardState != 0){
            redrawBoard();
        }

    }
    vector<int> move = this->computerPlayer->makeComputerMove(this->board->getBoard()); //Now We want to pass through the current board status in order to determine the move of the compute r
    this->board->setBoardMove(move[0],move[1],O);//Set the board position

    setMove_UI(move[0],move[1],COMPUTERPLAYER);
    this->board->PrintBoard(); //Printing out for debugging purposes
    //AlsoF we want to check if there are no other moves in the game
    currentBoardState_Computer = this->board->checkState(move[0],move[1],O);
    if (currentBoardState_Computer != 0){
        redrawBoard();
    }


    qDebug() << "Board State from human player: " << currentBoardState << "Board state from computer " << currentBoardState_Computer;

}

void MainWindow::on_row1col0_clicked()
{
    unsigned int currentBoardState;
    unsigned int currentBoardState_Computer;

    const int IPOSITION = 1;
    const int JPOSITION = 0;

    if(this->board->setBoardMove(IPOSITION,JPOSITION,1) == true){
        setMove_UI(IPOSITION,JPOSITION,HUMANPLAYER);
        currentBoardState = this->board->checkState(IPOSITION,JPOSITION,X);
        if (currentBoardState != 0){
            redrawBoard();
        }

    }
    vector<int> move = this->computerPlayer->makeComputerMove(this->board->getBoard()); //Now We want to pass through the current board status in order to determine the move of the compute r
    this->board->setBoardMove(move[0],move[1],O);//Set the board position

    setMove_UI(move[0],move[1],COMPUTERPLAYER);
    this->board->PrintBoard(); //Printing out for debugging purposes
    //AlsoF we want to check if there are no other moves in the game
    currentBoardState_Computer = this->board->checkState(move[0],move[1],O);
    if (currentBoardState_Computer != 0){
        redrawBoard();
    }


    qDebug() << "Board State from human player: " << currentBoardState << "Board state from computer " << currentBoardState_Computer;


}

void MainWindow::on_row1col1_clicked()
{
    unsigned int currentBoardState;
    unsigned int currentBoardState_Computer;

    const int IPOSITION = 1;
    const int JPOSITION = 1;
    if(this->board->setBoardMove(IPOSITION,JPOSITION,1) == true){
        setMove_UI(IPOSITION,JPOSITION,HUMANPLAYER);
        currentBoardState = this->board->checkState(IPOSITION,JPOSITION,X);
        if (currentBoardState != 0){
            redrawBoard();
        }

    }
    vector<int> move = this->computerPlayer->makeComputerMove(this->board->getBoard()); //Now We want to pass through the current board status in order to determine the move of the compute r
    this->board->setBoardMove(move[0],move[1],O);//Set the board position

    setMove_UI(move[0],move[1],COMPUTERPLAYER);
    this->board->PrintBoard(); //Printing out for debugging purposes
    //AlsoF we want to check if there are no other moves in the game
    currentBoardState_Computer = this->board->checkState(move[0],move[1],O);
    if (currentBoardState_Computer != 0){
        redrawBoard();
    }


    qDebug() << "Board State from human player: " << currentBoardState << "Board state from computer " << currentBoardState_Computer;

}


void MainWindow::on_row2col0_clicked()
{
    unsigned int currentBoardState;
    unsigned int currentBoardState_Computer;

    const int IPOSITION = 2;
    const int JPOSITION = 0;

    if(this->board->setBoardMove(IPOSITION,JPOSITION,1) == true){
        setMove_UI(IPOSITION,JPOSITION,HUMANPLAYER);
        currentBoardState = this->board->checkState(IPOSITION,JPOSITION,X);
        if (currentBoardState != 0){
            redrawBoard();
        }

    }
    vector<int> move = this->computerPlayer->makeComputerMove(this->board->getBoard()); //Now We want to pass through the current board status in order to determine the move of the compute r
    this->board->setBoardMove(move[0],move[1],O);//Set the board position

    setMove_UI(move[0],move[1],COMPUTERPLAYER);
    this->board->PrintBoard(); //Printing out for debugging purposes
    //AlsoF we want to check if there are no other moves in the game
    currentBoardState_Computer = this->board->checkState(move[0],move[1],O);
    if (currentBoardState_Computer != 0){
        redrawBoard();
    }


    qDebug() << "Board State from human player: " << currentBoardState << "Board state from computer " << currentBoardState_Computer;


}

void MainWindow::on_row2col1_clicked()
{
    unsigned int currentBoardState;
    unsigned int currentBoardState_Computer;

    const int IPOSITION = 2;
    const int JPOSITION = 1;

    if(this->board->setBoardMove(IPOSITION,JPOSITION,1) == true){
        setMove_UI(IPOSITION,JPOSITION,HUMANPLAYER);
        currentBoardState = this->board->checkState(IPOSITION,JPOSITION,X);
        if (currentBoardState != 0){
            redrawBoard();
        }

    }
    vector<int> move = this->computerPlayer->makeComputerMove(this->board->getBoard()); //Now We want to pass through the current board status in order to determine the move of the compute r
    this->board->setBoardMove(move[0],move[1],O);//Set the board position

    setMove_UI(move[0],move[1],COMPUTERPLAYER);
    this->board->PrintBoard(); //Printing out for debugging purposes
    //AlsoF we want to check if there are no other moves in the game
    currentBoardState_Computer = this->board->checkState(move[0],move[1],O);
    if (currentBoardState_Computer != 0){
        redrawBoard();
    }


    qDebug() << "Board State from human player: " << currentBoardState << "Board state from computer " << currentBoardState_Computer;


}

void MainWindow::on_row2col2_clicked()
{
    unsigned int currentBoardState;
    unsigned int currentBoardState_Computer;
    const int IPOSITION = 2;
    const int JPOSITION = 2;

    if(this->board->setBoardMove(IPOSITION,JPOSITION,1) == true){
        setMove_UI(IPOSITION,JPOSITION,HUMANPLAYER);
        currentBoardState = this->board->checkState(IPOSITION,JPOSITION,X);
        if (currentBoardState != 0){
            redrawBoard();
        }

    }
    vector<int> move = this->computerPlayer->makeComputerMove(this->board->getBoard()); //Now We want to pass through the current board status in order to determine the move of the compute r
    this->board->setBoardMove(move[0],move[1],O);//Set the board position

    setMove_UI(move[0],move[1],COMPUTERPLAYER);
    this->board->PrintBoard(); //Printing out for debugging purposes

    //AlsoF we want to check if there are no other moves in the game
    currentBoardState_Computer = this->board->checkState(move[0],move[1],O);
    if (currentBoardState_Computer != 0){
        redrawBoard();
    }


    qDebug() << "Board State from human player: " << currentBoardState << "Board state from computer " << currentBoardState_Computer;


}
void MainWindow::deliverConfirmationMessage(unsigned currentBoardStateNumber)
{
    //this function will perform the necesssary tasks of removing the the X and Os
    //from the board and prompting the appropriate UI elementss
    if (currentBoardStateNumber == 1){
        //Show that Player X has in fact won the game

    }


}
void MainWindow::redrawBoard(){
    //This function will loop through all of the board states and redraw them

    for (int i = 0; i < 3; i++){
        for (int j =0; j < 3;j++){
            setMove_UI(i,j,"");//This will set the board to no text


        }

    }

}
void MainWindow::on_row1col2_clicked()
{
    unsigned int currentBoardState;
    unsigned int currentBoardState_Computer;

    const int IPOSITION = 1;
    const int JPOSITION = 2;
    if(this->board->setBoardMove(IPOSITION,JPOSITION,1) == true){
        setMove_UI(IPOSITION,JPOSITION,HUMANPLAYER);
        currentBoardState = this->board->checkState(IPOSITION,JPOSITION,X);
        if (currentBoardState != 0){
            redrawBoard();
        }

    }
    vector<int> move = this->computerPlayer->makeComputerMove(this->board->getBoard()); //Now We want to pass through the current board status in order to determine the move of the compute r
    this->board->setBoardMove(move[0],move[1],O);//Set the board position

    setMove_UI(move[0],move[1],COMPUTERPLAYER);

    this->board->PrintBoard(); //Printing out for debugging purposes
    //AlsoF we want to check if there are no other moves in the game
    currentBoardState_Computer = this->board->checkState(move[0],move[1],O);

    if (currentBoardState_Computer != 0){
        redrawBoard();
    }


    qDebug() << "Board State from human player: " << currentBoardState << "Board state from computer " << currentBoardState_Computer;
    //printboard_Debugger()


}

