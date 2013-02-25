#ifndef MEMORYGRAPHICSWIDGET_H
#define MEMORYGRAPHICSWIDGET_H

#include <QGraphicsWidget>
#include <QGraphicsGridLayout>
#include <QMessageBox>
#include <QDebug>
#include <QGraphicsScene>

#include "include/i_memory.h"
#include "include/memory_card.h"
#include "include/qt_state.h"
#include "include/qt_state_first.h"
#include "include/qt_state_second.h"
#include "include/qt_state_end.h"
#include "include/qt_state_game_over.h"

class MemoryGraphicsWidget : public QGraphicsWidget
{
    Q_OBJECT
    friend class Qt_State_first;
    friend class Qt_State_second;
    friend class Qt_State_end;
public:
    explicit MemoryGraphicsWidget(I_Memory *game, QGraphicsScene *scene, QObject *parent = 0);
    bool eventFilter(QObject *object, QEvent *event);
protected:
private:
    QGraphicsGridLayout *_grid;
    QGraphicsScene *_scene;
    I_Memory *_game;
    Memory_Card ***_cards;

    bool _set_cards();

    //States (same as in the Engine

    Qt_State_first _first;
    Qt_State_second _second;
    Qt_State_end _end;
    Qt_State_game_over _game_over;

    Qt_State *_state;


signals:
    
public slots:
    void selection_change(int row, int column, bool selected);
    void turn_card(int row, int column);

    
};

#endif // MEMORYGRAPHICSWIDGET_H
