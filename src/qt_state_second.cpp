#include "include/qt_state_second.h"
#include "include/memorygraphicswidget.h"

Qt_State_second::Qt_State_second(MemoryGraphicsWidget *widget) :
    Qt_State(widget)
{
}

void Qt_State_second::turn(int row, int column)
{
    qDebug() << "in second turn state";
    graphicswidget->_cards[row][column]->turn();

}
