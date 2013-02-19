#include "include/player_wizzard.h"
#include "ui_player_wizzard.h"
#include <QInputDialog>

player_wizzard::player_wizzard(Memory *game, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::player_wizzard),
    _game(game)
{
    ui->setupUi(this);
    ui->listWidget->setIconSize(QSize(50,50));
    ui->next_button->setDisabled(true);

    //Just for debuging
    QListWidgetItem *item1 = new QListWidgetItem(QIcon("/home/tuxflo/Pictures/joris_mosh.JPG"),"BlueHills",ui->listWidget);
    ui->next_button->setDisabled(false);
}

player_wizzard::~player_wizzard()
{
    delete ui;
}

void player_wizzard::on_add_player_button_clicked()
{
    //QListWidgetItem *item1 = new QListWidgetItem(QIcon("/home/tuxflo/Pictures/joris_mosh.JPG"),"BlueHills",ui->listWidget);
    QString itemText = QInputDialog::getText(this, tr("New Player"),
           tr("Enter Name for the new Player:"));

       if (itemText.isNull())
           return;


       QListWidgetItem *newItem = new QListWidgetItem;
       newItem->setText(itemText);
       newItem->setIcon(QIcon("/home/tuxflo/Pictures/joris_mosh.JPG"));

       int row = ui->listWidget->row(ui->listWidget->currentItem());

       ui->listWidget->insertItem(row, newItem);
       ui->next_button->setDisabled(false);
}

void player_wizzard::on_remove_player_button_clicked()
{
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
