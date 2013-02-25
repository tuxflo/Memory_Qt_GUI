#include "include/qt_state_game_over.h"

Qt_State_game_over::Qt_State_game_over(MemoryGraphicsWidget *widget) :
    Qt_State(widget)
{
}

void Qt_State_game_over::turn(int row, int column)
{
    qDebug() << "Game over!";
    qDebug() << "Start animation, show highscore, ask for new game...";
}
