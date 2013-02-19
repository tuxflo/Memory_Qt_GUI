#include "include/mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    _game = new Memory;
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_new_game_button_clicked()
{
    _new_game_wizzard();
}

void MainWindow::_new_game_wizzard()
{
    _player_wizzard = new player_wizzard(_game);
    setCentralWidget(_player_wizzard);
}
