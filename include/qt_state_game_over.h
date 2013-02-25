#ifndef QT_STATE_GAME_OVER_H
#define QT_STATE_GAME_OVER_H

#include "include/qt_state.h"

class Qt_State_game_over : public Qt_State
{
public:
    Qt_State_game_over(MemoryGraphicsWidget *widget);
    void turn(int row, int column);
};

#endif // QT_STATE_GAME_OVER_H
