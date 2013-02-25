#include "include/qt_state_first.h"
#include "include/memorygraphicswidget.h"
Qt_State_first::Qt_State_first(MemoryGraphicsWidget *widget) :
    Qt_State(widget)
{ 
}

void Qt_State_first::turn(int row, int column)
{
    qDebug() << "in first turn state";
    graphicswidget->_cards[row][column]->turn();
    graphicswidget->_state = & graphicswidget->_second;
}
