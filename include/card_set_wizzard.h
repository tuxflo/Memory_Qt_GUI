#ifndef CARD_SET_WIZZARD_H
#define CARD_SET_WIZZARD_H

#include <QWidget>
#include <QGridLayout>
#include <QDir>
#include <QLabel>
#include <QMessageBox>
#include <QDebug>
#include <QListView>
#include <QListWidgetItem>
#include "include/memory.h"

namespace Ui {
class Card_Set_Wizzard;
}

class Card_Set_Wizzard : public QWidget
{
    Q_OBJECT
    
public:
    explicit Card_Set_Wizzard(Memory *game, QWidget *parent = 0);
    ~Card_Set_Wizzard();
signals:
    void card_setted();
    void back();

private slots:
    void on_next_button_clicked();
    void _set_num_of_cards();

    void on_back_button_clicked();

private:
    Ui::Card_Set_Wizzard *ui;

    QList<QListWidgetItem*> *_item_list;
    Memory *_game;
    QString *_folder_path;

};

#endif // CARD_SET_WIZZARD_H
