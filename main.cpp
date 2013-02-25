#include "include/mainwindow.h"
#include <QApplication>

#include "include/memory_card.h"
#include "include/card.h"
#include "include/i_memory.h"
#include "include/memory.h"
#include "include/qplayer.h"


//Just for testing
#include <QtGui>
int main(int argc, char *argv[])
{
     QApplication a(argc, argv);
    MainWindow w;
    w.show();
//    Memory_Card *card = new Memory_Card(0,0,0, "/home/tuxflo/workspace/Memory_Qt_GUI/Pictures/Capitols_of_Latin_America/svg/cover.svg", "/home/tuxflo/workspace/Memory_Qt_GUI/Pictures/Capitols_of_Latin_America/svg/cover.svg");
//    QGraphicsView *view = new QGraphicsView;
//    QGraphicsScene *scene = new QGraphicsScene;
//    QGraphicsWidget *wid = new QGraphicsWidget;
//    QGraphicsGridLayout *grid = new QGraphicsGridLayout;
//    grid->addItem(card, 0, 0);
//    wid->setLayout(grid);
//    scene->addItem(wid);
//    view->setScene(scene);
//    view->show();

    return a.exec();
}
