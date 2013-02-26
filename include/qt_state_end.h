#ifndef QT_STATE_END_H
#define QT_STATE_END_H

#include <QObject>
#include <QTimer>

#include "include/qt_state.h"
class Qt_State_end : public QObject, public Qt_State
{
    Q_OBJECT
public:
    Qt_State_end(MemoryGraphicsWidget *widget);
    ~Qt_State_end();
    void turn(int row, int column);
private slots:
    void turn_back();
};

#endif // QT_STATE_END_H
