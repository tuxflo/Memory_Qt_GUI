#ifndef CARD_SET_WIZZARD_H
#define CARD_SET_WIZZARD_H

#include <QWidget>
#include <QGridLayout>
#include <QDir>
#include <QLabel>
#include <QMessageBox>
#include <QDebug>
#include <QListView>
#include <QStandardItemModel>

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
    
private slots:
    void on_next_button_clicked();

private:
    Ui::Card_Set_Wizzard *ui;
    QStandardItemModel *_model;
    QList<QStandardItem*> *_item_list;
    Memory *_game;

};

#endif // CARD_SET_WIZZARD_H
