#ifndef QT_STATE_GAME_OVER_H
#define QT_STATE_GAME_OVER_H

#include <QTimer>
#include "include/qt_state.h"
#include "include/highscoredialog.h"

class Qt_State_game_over : public QObject, public Qt_State
{
    Q_OBJECT
public:
    Qt_State_game_over(MemoryGraphicsWidget *widget);
    ~Qt_State_game_over();
    void turn(int row, int column);
private:
    int index;
    QTimer *timer;
signals:
public slots:
    void hover_next();
};

#endif // QT_STATE_GAME_OVER_H
