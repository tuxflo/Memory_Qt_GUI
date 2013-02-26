#ifndef MEMORY_WIDGET_H
#define MEMORY_WIDGET_H

#include <QWidget>
#include <QGraphicsScene>

#include "include/i_memory.h"
#include "include/qplayer.h"
#include "include/memorygraphicswidget.h"


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
    MemoryGraphicsWidget *_graphics_widget;

    I_Memory *_game;

public slots:
    void set_player();
};

#endif // MEMORY_WIDGET_H
