#ifndef QT_STATE_SECOND_H
#define QT_STATE_SECOND_H

#include "include/qt_state.h"

class Qt_State_second : public Qt_State
{
public:
    Qt_State_second(MemoryGraphicsWidget *widget);
    void turn(int row, int column);
};

#endif // QT_STATE_SECOND_H
