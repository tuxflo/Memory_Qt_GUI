#include "include/qt_state_end.h"

#include "include/memorygraphicswidget.h"
Qt_State_end::Qt_State_end(MemoryGraphicsWidget *widget) :
    Qt_State(widget)
{
}

void Qt_State_end::turn(int row, int column)
{
    qDebug() << "End turn state chck if the cards match!";
}
