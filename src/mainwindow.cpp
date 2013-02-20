#include "include/mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    _player_wizzard(0),
    _card_wizzard(0)
{
    ui->setupUi(this);
    _game = new Memory;



    _stacked_widget = new QStackedWidget(this);
    _main_menu = new Main_Menu(_stacked_widget);

    //Connect the Buttons of the main menu
    connect(_main_menu, SIGNAL(new_game()), this, SLOT(_new_game_wizzard()));
    connect(_main_menu, SIGNAL(help()), this, SLOT(_help()));
    connect(_main_menu, SIGNAL(quit()), this, SLOT(_quit()));

    _stacked_widget->insertWidget(0, _main_menu);
    _stacked_widget->setCurrentIndex(0);
    //_stacked_widget->addWidget(_main_menu);
    setCentralWidget(_stacked_widget);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::_card_set_wizzard()
{
    if(_card_wizzard == 0)
    {
        _card_wizzard = new Card_Set_Wizzard(_game, _stacked_widget);
        connect(_card_wizzard, SIGNAL(card_setted()), this, SLOT(_new_game()));
        connect(_card_wizzard, SIGNAL(back()), this, SLOT(_back()));
    }
    //_stacked_widget->addWidget(_card_wizzard);
    _stacked_widget->insertWidget(2, _card_wizzard);
    _stacked_widget->setCurrentIndex(2);
    setWindowTitle("Select the Card-Set");

}

void MainWindow::_new_game()
{
    //Here starts the "real" game
    _memory_widget = new Memory_Widget();
    setCentralWidget(_memory_widget);
}

void MainWindow::_help()
{
}

void MainWindow::_quit()
{
    //Leave the Application
    QApplication::quit();
}

void MainWindow::_back()
{
    switch(_stacked_widget->currentIndex())
    {
        case 1:
            _stacked_widget->setCurrentIndex(0);
            break;
        case 2:
            _stacked_widget->setCurrentIndex(1);
            break;
    }
}

void MainWindow::_new_game_wizzard()
{
    if(_player_wizzard == 0)
    {
        //There was no player_wizard before
        _player_wizzard = new player_wizzard(_game, _stacked_widget);
        connect(_player_wizzard, SIGNAL(card_set_wizzard()), this, SLOT(_card_set_wizzard()));
        connect(_player_wizzard, SIGNAL(back()), this, SLOT(_back()));
    }
    //_stacked_widget->addWidget(_player_wizzard);
    _stacked_widget->insertWidget(1, _player_wizzard);
    _stacked_widget->setCurrentIndex(1);
    setWindowTitle("Edit Players");

}

void MainWindow::on_actionExit_triggered()
{
    _quit();
}
