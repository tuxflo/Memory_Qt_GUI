#include "include/memory_widget.h"
#include "ui_memory_widget.h"

#include <QDebug>

Memory_Widget::Memory_Widget(I_Memory *game, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Memory_Widget),
    _game(game)
{
    ui->setupUi(this);

    //Show the first player
    Player *tmp = _game->get_active_player();
    QPLayer *tmp_player = dynamic_cast<QPLayer*>(_game->get_active_player());
    ui->player_name->setText(tmp->get_name().c_str());
    ui->player_icon->setPixmap(tmp_player->get_icon().pixmap(ui->player_icon->size(), QIcon::Normal, QIcon::On));
    ui->player_score->setText(QString::number(tmp->get_score()));

    //Set up the scene
    _scene = new QGraphicsScene;
    _graphics_widget = new MemoryGraphicsWidget(game, _scene);
    _scene->addItem(_graphics_widget);
    ui->graphicsView->setScene(_scene);

}

Memory_Widget::~Memory_Widget()
{
    delete ui;
}
