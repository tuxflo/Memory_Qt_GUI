#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "player_wizzard.h"
#include "include/memory.h"
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
    void on_new_game_button_clicked();

private:
    Ui::MainWindow *ui;
    void _new_game_wizzard();
    player_wizzard *_player_wizzard;

    //The game engine
    Memory *_game;
};

#endif // MAINWINDOW_H
