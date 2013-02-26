#include "include/qt_state_end.h"

#include "include/memorygraphicswidget.h"
Qt_State_end::Qt_State_end(MemoryGraphicsWidget *widget) :
    Qt_State(widget)
{
}

Qt_State_end::~Qt_State_end()
{
}

void Qt_State_end::turn(int row, int column)
{
    qDebug() << "End turn state check if the cards match!";
    if(graphicswidget->_game->get_recieved_points() > 0)
    {
        //The cards match!
        if(graphicswidget->_game->get_game_over())
            graphicswidget->_state = &graphicswidget->_game_over;
        graphicswidget->_turned_card = false;
    }
    else
    {
        QTimer::singleShot(1500, this, SLOT(turn_back()));
    }
    graphicswidget->_state = &graphicswidget->_first;
}

void Qt_State_end::turn_back()
{

    graphicswidget->_first_card->turn_back();
    graphicswidget->_second_card->turn_back();
    graphicswidget->_turned_card = false;
    graphicswidget->send_player_change();
}
