#include "include/highscoredialog.h"
#include "ui_highscoredialog.h"
#include "include/qplayer.h"
#include <QColor>
#include <QIcon>

HighscoreDialog::HighscoreDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::HighscoreDialog)
{
    ui->setupUi(this);
    QVector<QPLayer> players;
    QVector<QTableWidgetItem*> items;
    QSettings settings("tuxflo", "Memory_Qt_GUI");
    settings.beginGroup("highscore");
    int s = settings.beginReadArray("highscore");

    for(int i=0; i< s; i++)
    {
        settings.setArrayIndex(i);
        QPLayer tmp;
        tmp.set_color(settings.value("playercolor").value<QColor>());
        tmp.set_icon(settings.value("playericon").value<QIcon>());
        tmp.set_name(settings.value("playername").toString().toAscii().data());
        tmp.add_points(settings.value("playerscore").toInt());
        qDebug() << tmp.get_name().c_str();
        players.push_back(tmp);
        items.push_back(new QTableWidgetItem);
        items.last()->setData(Qt::EditRole, players.last().get_score());
        items.last()->setBackgroundColor(players.last().get_color());

    }
    settings.endArray();
    settings.endGroup();


    ui->tableWidget->setColumnCount(2);
    QStringList columnnames;
    columnnames <<"Player"<<"Score";
    ui->tableWidget->setHorizontalHeaderLabels(columnnames);
    ui->tableWidget->horizontalHeader()->setResizeMode(0, QHeaderView::Stretch );
    ui->tableWidget->setIconSize(QSize(50,50));
    ui->tableWidget->setRowCount(items.size());

    for(int j=0; j<items.size(); j++)
    {
        ui->tableWidget->setItem(j, 0, new QTableWidgetItem(QIcon(players[j].get_icon()), players[j].get_name().c_str()));
        ui->tableWidget->item(j, 0)->setBackgroundColor(players[j].get_color());
        ui->tableWidget->setItem(j, 1, items.at(j));
    }

    ui->tableWidget->sortByColumn(1, Qt::DescendingOrder);
    ui->tableWidget->setSortingEnabled(true);
    ui->tableWidget->setColumnWidth(1, 100);
    ui->tableWidget->setColumnWidth(0, size().width()- 120);
    ui->tableWidget->setIconSize(QSize(60, 60));

}

HighscoreDialog::~HighscoreDialog()
{
    delete ui;
}
