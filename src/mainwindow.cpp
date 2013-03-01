#include "include/mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    _player_wizzard(0),
    _card_wizzard(0)
{
    ui->setupUi(this);
    //Set the widget pointer to 0
    _memory_widget = 0;
    _player_wizzard = 0;
    _card_wizzard = 0;
    _game = 0;



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
    qDebug() << "MainWindow Destructor!";
    delete _game;
    if(!_memory_widget)
        delete _memory_widget;
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
    _memory_widget = new Memory_Widget(_game, this);
    //setCentralWidget(_memory_widget);
    _stacked_widget->insertWidget(3, _memory_widget);
    _stacked_widget->setCurrentIndex(3);
    setMinimumSize(_memory_widget->geometry().size());
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
    _stacked_widget->setCurrentIndex(_stacked_widget->currentIndex()-1);
}

void MainWindow::_new_game_wizzard()
{
    if(_game == 0)
        _game = new Memory;
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

void MainWindow::on_actionNew_Game_triggered()
{
    if(_memory_widget != 0)
    {
        delete _memory_widget;
        _memory_widget = 0;
    }
    if(_card_wizzard != 0)
    {
        delete _card_wizzard;
        _card_wizzard = 0;
    }
    if(_player_wizzard != 0)
    {
        delete _player_wizzard;
        _player_wizzard = 0;
    }
    if(_game != 0)
    {
        delete _game;
        _game = 0;
    }
    _new_game_wizzard();

}
