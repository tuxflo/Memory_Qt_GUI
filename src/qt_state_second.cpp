#include "include/qt_state_second.h"
#include "include/memorygraphicswidget.h"

Qt_State_second::Qt_State_second(MemoryGraphicsWidget *widget) :
    Qt_State(widget)
{
}

Qt_State_second::~Qt_State_second()
{
}

void Qt_State_second::turn(int row, int column)
{
    qDebug() << "in second turn state";
    if(graphicswidget->_game->get_turned(row, column))
        return;
    graphicswidget->_game->turn(row, column);
    graphicswidget->_second_card = graphicswidget->_cards[row * graphicswidget->_game->get_rows() + column];

    graphicswidget->_second_card->turn();
    graphicswidget->_turned_card = true;
    graphicswidget->_state = &graphicswidget->_end;
    graphicswidget->_state->turn(row, column);


}
