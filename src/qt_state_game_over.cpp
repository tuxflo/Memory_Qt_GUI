#include "include/qt_state_game_over.h"
#include "include/memorygraphicswidget.h"

Qt_State_game_over::Qt_State_game_over(MemoryGraphicsWidget *widget) :
    Qt_State(widget),
    index(0)
{
}

Qt_State_game_over::~Qt_State_game_over()
{
}

void Qt_State_game_over::turn(int row, int column)
{
    qDebug() << "Game over!" << "row: " << row << "column: " << column;
    qDebug() << "Start animation, show highscore, ask for new game...";
    for(int i=0; i< graphicswidget->_cards.size(); i++)
    {
        graphicswidget->_cards.at(i)->disconnect(SIGNAL(selection_change(int, int)));
        graphicswidget->_cards.at(i)->disconnect(SIGNAL(clicked(int,int)));
    }
    timer = new QTimer;
    connect(timer, SIGNAL(timeout()), this, SLOT(hover_next()));
    timer->start(300);

    //Create highscore
    QSettings settings("tuxflo", "Memory_Qt_GUI");
    settings.beginGroup("highscore");
    //settings.remove("");
    int size = settings.beginReadArray("highscore");
    settings.endArray();
    settings.beginWriteArray("highscore");
    for (int i = 0; i < graphicswidget->_game->get_num_of_players(); i++)
    {
        settings.setArrayIndex(i+size);
        QPLayer *player = dynamic_cast<QPLayer*>(graphicswidget->_game->get_player_at(i));
        //QVariant a = qVariantFromValue(player);
        settings.setValue("playername", player->get_name().c_str());
        settings.setValue("playerscore", player->get_score());
        settings.setValue("playercolor", player->get_color());
        settings.setValue("playericon", player->get_icon());
    }
    settings.endArray();
    settings.sync();

    HighscoreDialog highscore;
    highscore.exec();
}

void Qt_State_game_over::hover_next()
{
    if(index == graphicswidget->_cards.size())
        index = 0;
    if(index == 0)
    {
        graphicswidget->_cards.last()->set_selected(false);
        graphicswidget->_cards.at(index)->set_selected(true);
    }
    else
    {
        graphicswidget->_cards.at(index-1)->set_selected(false);
        graphicswidget->_cards.at(index)->set_selected(true);
    }
    index++;
}
