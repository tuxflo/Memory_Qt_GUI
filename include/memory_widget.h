#ifndef MEMORY_WIDGET_H
#define MEMORY_WIDGET_H

#include <QWidget>
#include <QGraphicsScene>
#include <QGraphicsWidget>
#include <QGraphicsGridLayout>

#include "include/i_memory.h"
#include "include/qplayer.h"


namespace Ui {
class Memory_Widget;
}

class Memory_Widget : public QWidget
{
    Q_OBJECT
    
public:
    explicit Memory_Widget(I_Memory *game, QWidget *parent = 0);
    ~Memory_Widget();
    
private:
    Ui::Memory_Widget *ui;
    QGraphicsScene *_scene;
    QGraphicsWidget *_graphics_widget;
    QGraphicsGridLayout *_grid;

    I_Memory *_game;
};

#endif // MEMORY_WIDGET_H
