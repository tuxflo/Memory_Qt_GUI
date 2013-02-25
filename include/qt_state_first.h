#ifndef QT_STATE_FIRST_H
#define QT_STATE_FIRST_H

#include "include/qt_state.h"

class Qt_State_first : public Qt_State
{
public:
    Qt_State_first(MemoryGraphicsWidget *widget);
    void turn(int row, int column);
};

#endif // QT_STATE_FIRST_H
