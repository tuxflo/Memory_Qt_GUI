#ifndef QT_STATE_H
#define QT_STATE_H

#include <QDebug>

class MemoryGraphicsWidget;
class Qt_State
{
public:
    Qt_State(MemoryGraphicsWidget *widget);
    virtual void turn(int row, int column)=0;
protected:
    MemoryGraphicsWidget *graphicswidget;
};

#endif // QT_STATE_H
