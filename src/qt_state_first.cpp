#include "include/qt_state_first.h"
#include "include/memorygraphicswidget.h"
Qt_State_first::Qt_State_first(MemoryGraphicsWidget *widget) :
    Qt_State(widget)
{ 
}

void Qt_State_first::turn(int row, int column)
{
    qDebug() << "in first turn state";
    if(graphicswidget->_game->get_turned(row, column))
        return;
    graphicswidget->_game->turn(row, column);
    graphicswidget->_first_card = graphicswidget->_cards[row * graphicswidget->_game->get_rows() + column];
    graphicswidget->_first_card->turn();
    graphicswidget->_state = & graphicswidget->_second;
}
