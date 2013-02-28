#include "include/memorygraphicswidget.h"

MemoryGraphicsWidget::MemoryGraphicsWidget(I_Memory *game, QGraphicsScene *scene, QObject *parent) :
    _game(game),
    _scene(scene),
    _first(this),
    _second(this),
    _end(this),
    _game_over(this),
    _state(&_first),
    _turned_card(false)
{
    _grid = new QGraphicsGridLayout;
    _game->set_cards();
    if(!_set_cards())
    {
        QMessageBox::critical(0, tr("Error"),
                                       tr("Setting cards failed. Please send a bugreport to the contact listet in About or help"),QMessageBox::Ok);
    }
    _scene->installEventFilter(this);
}

bool MemoryGraphicsWidget::eventFilter(QObject *object, QEvent *event)
{
    //Handle Keyboard commands
    if(event->type() == QEvent::KeyPress)
    {
        QKeyEvent *key = static_cast<QKeyEvent *>(event);
        if(_scene->selectedItems().isEmpty())
        {
            selection_change(0, 0, true);
            return true;
        }
        QGraphicsItem *selected_item = _scene->selectedItems().first();
        Memory_Card *selected_card = qgraphicsitem_cast<Memory_Card *>(selected_item);
        switch(key->key())
        {
            case Qt::Key_Space:
            qDebug() << "Space";
            turn_card(selected_card->get_row(), selected_card->get_column());
            break;
        case Qt::Key_Left:
            if(selected_card->get_column() > 0)
            {
            selection_change(selected_card->get_row(), selected_card->get_column(), false);
            selection_change(selected_card->get_row(), selected_card->get_column()-1, true);
            }

            break;
        case Qt::Key_Right:
            if(selected_card->get_column() < _game->get_columns()-1)
            {
            selection_change(selected_card->get_row(), selected_card->get_column(), false);
            selection_change(selected_card->get_row(), selected_card->get_column()+1, true);
            }
            break;
        case Qt::Key_Up:
            if(selected_card->get_row() > 0)
            {
            selection_change(selected_card->get_row(), selected_card->get_column(), false);
            selection_change(selected_card->get_row()-1, selected_card->get_column(), true);
            }
            break;
        case Qt::Key_Down:
            if(selected_card->get_row() < _game->get_columns()-1)
            {
            selection_change(selected_card->get_row(), selected_card->get_column(), false);
            selection_change(selected_card->get_row()+1, selected_card->get_column(), true);
            }
            break;
        }
        return true;
    }
    return false;
}

void MemoryGraphicsWidget::resizeEvent(QSize newsize)
{
//    qDebug() << "resize event!" << _scene->width() << " " << _scene->height();
//    for(int i=0; i<_game->get_rows()*_game->get_columns(); i++)
//    {
//        _grid->setColumnFixedWidth(i/_game->get_columns(), newsize.width() /(_game->get_columns()+2));
//        _grid->setRowFixedHeight(i - (i/_game->get_columns() * _game->get_rows()), newsize.height()/(_game->get_rows()+2));
//        _cards.at(i)->set_size(newsize.width()/(_game->get_columns()+2), newsize.height()/(_game->get_rows()+2));
//    }
}

bool MemoryGraphicsWidget::_set_cards()
{
    QPLayer *tmp_player = dynamic_cast<QPLayer*>(_game->get_active_player());
    for(int i=0; i<_game->get_rows() * _game->get_columns(); i++)
    {
        int row = i/_game->get_columns();
        int column = i - (row * _game->get_columns());
        _cards.push_back(new Memory_Card(row, column, _game->get_card(i), _game->get_cover().c_str()));
        _cards.at(i)->set_hover_color(tmp_player->get_color());

        connect(_cards[i], SIGNAL(selection_change(int, int, bool)), this, SLOT(selection_change(int,int, bool)));
        connect(_cards[i], SIGNAL(clicked(int, int)), this, SLOT(turn_card(int, int)));
        _grid->addItem(_cards[i], row, column);
    }
    //Set focus on the first item
    _scene->setFocusItem(_cards[0]);
    _cards[0]->set_selected(true);
    setLayout(_grid);

    return true;
}

void MemoryGraphicsWidget::selection_change(int row, int column, bool selected)
{
    if(_scene->selectedItems().isEmpty())
        return;
    QGraphicsItem *selected_item = _scene->selectedItems().first();
    Memory_Card *selected_card = qgraphicsitem_cast<Memory_Card *>(selected_item);
    selected_card->set_selected(false);
    _cards[row * _game->get_columns() + column]->set_selected(true);
}

void MemoryGraphicsWidget::turn_card(int row, int column)
{
    if(!_turned_card)
    //Turn the card in the view
        _state->turn(row, column);
}

void MemoryGraphicsWidget::send_player_change()
{
    QPLayer *tmp_player = dynamic_cast<QPLayer*>(_game->get_active_player());
    emit player_change();
    for(int i=0; i<_cards.size();i++)
        _cards.at(i)->set_hover_color(tmp_player->get_color());
}
