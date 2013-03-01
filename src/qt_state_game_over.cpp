#include "include/qt_state_game_over.h"
#include "include/memorygraphicswidget.h"

Qt_State_game_over::Qt_State_game_over(MemoryGraphicsWidget *widget) :
    Qt_State(widget),
    index(0)
{
}

Qt_State_game_over::~Qt_State_game_over()
{
}

void Qt_State_game_over::turn(int row, int column)
{
    qDebug() << "Game over!" << "row: " << row << "column: " << column;
    qDebug() << "Start animation, show highscore, ask for new game...";
    for(int i=0; i< graphicswidget->_cards.size(); i++)
    {
        graphicswidget->_cards.at(i)->disconnect(SIGNAL(selection_change(int, int)));
        graphicswidget->_cards.at(i)->disconnect(SIGNAL(clicked(int,int)));
    }
    timer = new QTimer;
    connect(timer, SIGNAL(timeout()), this, SLOT(hover_next()));
    timer->start(300);
}

void Qt_State_game_over::hover_next()
{
    if(index == graphicswidget->_cards.size())
        index = 0;
    if(index == 0)
    {
        graphicswidget->_cards.last()->set_selected(false);
        graphicswidget->_cards.at(index)->set_selected(true);
    }
    else
    {
        graphicswidget->_cards.at(index-1)->set_selected(false);
        graphicswidget->_cards.at(index)->set_selected(true);
    }
    index++;
}
