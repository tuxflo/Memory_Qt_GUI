#include "include/mainwindow.h"
#include <QApplication>

#include "include/memory_card.h"
#include "include/card.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    Card *card = new Memory_Card;
    return a.exec();
}
