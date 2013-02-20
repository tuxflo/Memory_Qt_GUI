#ifndef PLAYER_WIZZARD_H
#define PLAYER_WIZZARD_H

#include <QWidget>
#include "include/memory.h"

namespace Ui {
class player_wizzard;
}

class player_wizzard : public QWidget
{
    Q_OBJECT
    
public:
    explicit player_wizzard(Memory *game, QWidget *parent = 0);
    ~player_wizzard();
signals:
    void card_set_wizzard();
    void back();
private slots:
    void on_add_player_button_clicked();

    void on_remove_player_button_clicked();

    void on_next_button_clicked();

    void on_back_button_clicked();

private:
    Ui::player_wizzard *ui;
    Memory *_game;
};

#endif // PLAYER_WIZZARD_H
