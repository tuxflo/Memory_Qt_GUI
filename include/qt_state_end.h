#ifndef QT_STATE_END_H
#define QT_STATE_END_H

#include "include/qt_state.h"
class Qt_State_end : public Qt_State
{
public:
    Qt_State_end(MemoryGraphicsWidget *widget);
    void turn(int row, int column);
};

#endif // QT_STATE_END_H
