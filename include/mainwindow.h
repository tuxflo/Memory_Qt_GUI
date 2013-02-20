#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QStackedWidget>
#include "player_wizzard.h"
#include "include/memory.h"
#include "card_set_wizzard.h"
#include "memory_widget.h"
#include "main_menu.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    
private slots:
    void _card_set_wizzard();
    void _new_game_wizzard();

    void _new_game();
    void _help();
    void _quit();
    void _back();

    void on_actionExit_triggered();

private:
    Ui::MainWindow *ui;
    player_wizzard *_player_wizzard;
    Card_Set_Wizzard *_card_wizzard;
    Memory_Widget *_memory_widget;
    //The game engine
    Memory *_game;
    QWidget *_current_widget;
    QStackedWidget *_stacked_widget;
    Main_Menu *_main_menu;
};

#endif // MAINWINDOW_H
