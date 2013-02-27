#include "include/player_wizzard.h"
#include "ui_player_wizzard.h"
#include <QInputDialog>

player_wizzard::player_wizzard(I_Memory *game, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::player_wizzard),
    _game(game)
{
    ui->setupUi(this);
    ui->listWidget->setIconSize(QSize(50,50));
    QPalette p = ui->listWidget->palette();
    p.setColor(QPalette::Highlight, Qt::darkGreen);
    ui->listWidget->setPalette(p);
    ui->next_button->setDisabled(true);

    //Just for debuging
//    QListWidgetItem *item1 = new QListWidgetItem(QIcon("/home/tuxflo/Pictures/joris_mosh.JPG"),"Player 1",ui->listWidget);
//    ui->listWidget->addItem(item1);
//    QPLayer *player = new QPLayer("Player 1");
//    player->set_icon(QIcon("/home/tuxflo/Pictures/joris_mosh.JPG"));
//    player->set_color(Qt::darkGreen);
//    _game->add_player(player);
//    ui->next_button->setDisabled(false);

    setParent(0);
}

player_wizzard::~player_wizzard()
{
    delete ui;
}

void player_wizzard::on_add_player_button_clicked()
{
       NewPlayerDialog dialog;
       //Return if the Player hit cancel button
       if(dialog.exec() == QDialog::Rejected)
           return;

       QString playername = dialog.get_name() ;
       //Return if there is no playername entered
       if(playername.isEmpty())
           return;
       QColor tmp = dialog.get_color();
       QListWidgetItem *newItem = new QListWidgetItem;
       newItem->setText(playername);
       newItem->setTextColor(tmp);
       newItem->setIcon(QIcon("/home/tuxflo/Pictures/joris_mosh.JPG"));

       int row = ui->listWidget->row(ui->listWidget->currentItem());

       ui->listWidget->insertItem(row, newItem);
       ui->next_button->setDisabled(false);
       //Add the player to the Memory_Enigne
       QPLayer *player = new QPLayer(playername);
<<<<<<< HEAD
       player->set_icon(QIcon("/home/tuxflo/Pictures/joris_mosh.JPG"));
       player->set_color(Qt::red);
=======

       //Set the icon of the player
       player->set_icon(dialog.get_icon());
       player->set_color(tmp);
>>>>>>> player_color_picker
       _game->add_player(player);

}

void player_wizzard::on_remove_player_button_clicked()
{
    _game->remove_player(ui->listWidget->currentItem()->text().toAscii().data());
    ui->listWidget->takeItem(ui->listWidget->row(ui->listWidget->currentItem()));
    if(ui->listWidget->count() == 0)
        ui->next_button->setDisabled(true);
    else
        ui->next_button->setDisabled(false);
}

void player_wizzard::on_next_button_clicked()
{
    emit card_set_wizzard();
}

void player_wizzard::on_back_button_clicked()
{
    emit back();
}
