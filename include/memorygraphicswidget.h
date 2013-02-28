#ifndef MEMORYGRAPHICSWIDGET_H
#define MEMORYGRAPHICSWIDGET_H

#include <QGraphicsWidget>
#include <QGraphicsGridLayout>
#include <QMessageBox>
#include <QDebug>
#include <QGraphicsScene>
#include <QVector>

#include "include/i_memory.h"
#include "include/qplayer.h"
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
    void resizeEvent(QSize newsize);

protected:
private:
    QGraphicsGridLayout *_grid;
    QGraphicsScene *_scene;
    I_Memory *_game;
    QVector<Memory_Card*> _cards;
    Memory_Card *_first_card;
    Memory_Card *_second_card;

    bool _set_cards();

    //States (same as in the Engine

    Qt_State_first _first;
    Qt_State_second _second;
    Qt_State_end _end;
    Qt_State_game_over _game_over;

    Qt_State *_state;

    //For checking that the cards can not be turned if there are aready 2 turned cards
    bool _turned_card;


signals:
    void player_change();
    
public slots:
    void selection_change(int row, int column, bool selected);
    void turn_card(int row, int column);
    void send_player_change();

    
};

#endif // MEMORYGRAPHICSWIDGET_H
