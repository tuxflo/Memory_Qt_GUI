#include "include/memory_widget.h"
#include "ui_memory_widget.h"

#include <QDebug>

Memory_Widget::Memory_Widget(I_Memory *game, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Memory_Widget),
    _game(game)
{
    ui->setupUi(this);
    qDebug() << _game->get_active_player()->get_name().c_str();
    Player *tmp = _game->get_active_player();
//    ui->player_name->setText(tmp->get_name().c_str());
    QPLayer *tmp_player = dynamic_cast<QPLayer*>(tmp);
    ui->player_name->setText(tmp->get_name().c_str());
    ui->player_icon->setPixmap(tmp_player->get_icon().pixmap(ui->player_icon->size(), QIcon::Normal, QIcon::On));
}

Memory_Widget::~Memory_Widget()
{
    delete ui;
}
