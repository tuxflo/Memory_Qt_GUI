#include "include/memorygraphicswidget.h"

MemoryGraphicsWidget::MemoryGraphicsWidget(I_Memory *game, QGraphicsScene *scene, QObject *parent) :
    _game(game),
    _scene(scene),
    _first(this),
    _second(this),
    _end(this),
    _game_over(this),
    _state(&_first)
{
    _grid = new QGraphicsGridLayout;
    _cards = new Memory_Card**[_game->get_rows()];
    for(int i=0; i< _game->get_rows(); i++)
        _cards[i] = new Memory_Card*[_game->get_columns()];
    _game->set_cards();
    if(!_set_cards())
    {
        QMessageBox::critical(0, tr("Error"),
                                       tr("Setting cards failed. Please send a bugreport to the contact listet in About or help"),QMessageBox::Ok);
    }

}

bool MemoryGraphicsWidget::eventFilter(QObject *object, QEvent *event)
{
    //Handle Keyboard commands
}

bool MemoryGraphicsWidget::_set_cards()
{
    for(int r=0; r<_game->get_rows(); r++)
    {
        for(int c=0; c<_game->get_columns(); c++)
        {
            _cards[r][c] = new Memory_Card(r, c, _game->get_card(r, c), _game->get_cover());
            connect(_cards[r][c], SIGNAL(selection_change(int, int, bool)), this, SLOT(selection_change(int,int, bool)));
            connect(_cards[r][c], SIGNAL(clicked(int, int)), this, SLOT(turn_card(int, int)));
            _grid->addItem(_cards[r][c], r, c);
        }
    }
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
    _cards[row][column]->set_selected(true);
}

void MemoryGraphicsWidget::turn_card(int row, int column)
{
    //Turn the card in the view
    _state->turn(row, column);

    //Turn the card in the Engine
    _game->turn(row, column);

}
