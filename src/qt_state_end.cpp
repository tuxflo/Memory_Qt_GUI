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
    qDebug() << "End turn state check if the cards match!" << "row: " << row << "column: " << column ;
    bool game_over = false;
    if(graphicswidget->_game->get_recieved_points() > 0)
    {
        //The cards match!
        if(graphicswidget->_game->get_game_over())
        {
            game_over = true;
            graphicswidget->_state = &graphicswidget->_game_over;
            graphicswidget->_state->turn(0,0);
        }
        graphicswidget->_turned_card = false;
    }
    else
    {
        QSettings settings("tuxflo", "Memory_Qt_GUI");
        settings.beginGroup("Card Settings");
        int delay = settings.value("cards delay").toInt();
        settings.endGroup();
        qDebug() << "Loaded setting cards delay: " << delay;
        QTimer::singleShot(delay, this, SLOT(turn_back()));
    }
    if(!game_over)
        graphicswidget->_state = &graphicswidget->_first;
    graphicswidget->send_player_change();

}

void Qt_State_end::turn_back()
{

    graphicswidget->_first_card->turn_back();
    graphicswidget->_second_card->turn_back();
    graphicswidget->_turned_card = false;
}
