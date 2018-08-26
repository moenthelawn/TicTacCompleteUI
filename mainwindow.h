#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "boardstate.h"
#include "computerai.h"
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_checkBox_stateChanged(int arg1);
    void redrawBoard();
    void setMove_UI(int i,int j,QString PlayerType);
    void displayState(unsigned int boardState);
    void on_row0col0_clicked();

    void on_row0col1_clicked();

    void on_row0col2_clicked();

    void on_row1col0_clicked();

    void on_row1col1_clicked();

    void on_row1col2_clicked();

    void on_row2col0_clicked();

    void on_row2col1_clicked();

    void on_row2col2_clicked();

    void deliverConfirmationMessage(unsigned currentBoardStateNumber);


    void on_frame_windowIconTextChanged(const QString &iconText);

    void on_GameWinner_linkActivated(const QString &link);

    void on_GameWinner_customContextMenuRequested(const QPoint &pos);

    void on_GameWinner_objectNameChanged(const QString &objectName);

private:
    Ui::MainWindow *ui;
    BoardState *board;
    ComputerAI *computerPlayer;
};

#endif // MAINWINDOW_H
