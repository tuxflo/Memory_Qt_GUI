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

void MainWindow::_card_set_wizzard()
{
    _card_wizzard = new Card_Set_Wizzard(_game, this);
    _card_wizzard->setFixedHeight(height());
    _card_wizzard->setFixedWidth(width());
    setCentralWidget(_card_wizzard);
    connect(_card_wizzard, SIGNAL(card_setted()), this, SLOT(_num_of_cards_wizzard()));
}

void MainWindow::_num_of_cards_wizzard()
{

}

void MainWindow::_new_game_wizzard()
{
    _player_wizzard = new player_wizzard(_game, this);
    setCentralWidget(_player_wizzard);
    connect(_player_wizzard, SIGNAL(card_set_wizzard()), this, SLOT(_card_set_wizzard()));
}
