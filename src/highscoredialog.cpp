#include "include/highscoredialog.h"
#include "ui_highscoredialog.h"
#include "include/qplayer.h"
HighscoreDialog::HighscoreDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::HighscoreDialog)
{
    ui->setupUi(this);
    QVector<QPLayer*> players;
    QSettings settings("tuxflo", "Memory_Qt_GUI");
    settings.beginGroup("highscore");
    int s = settings.beginReadArray("highscore");

    for(int i=0; i< s; i++)
    {
        settings.setArrayIndex(i);
        players.push_back(settings.value("player").value<QPLayer*>());
    }
    settings.endArray();
    settings.endGroup();


    ui->tableWidget->setColumnCount(2);
    QStringList columnnames;
    columnnames <<"Player"<<"Score";
    ui->tableWidget->setHorizontalHeaderLabels(columnnames);
    ui->tableWidget->horizontalHeader()->setResizeMode(0, QHeaderView::Stretch );
    ui->tableWidget->setIconSize(QSize(50,50));
    ui->tableWidget->setRowCount(5);
    QTableWidgetItem *item = new QTableWidgetItem;
    item->setData(Qt::EditRole, players.at(0)->get_score());
    QTableWidgetItem *item1 = new QTableWidgetItem;
    item1->setData(Qt::EditRole, players.at(1)->get_score());
    ui->tableWidget->setItem(0, 0, new QTableWidgetItem(players.at(0)->get_icon(), players.at(0)->get_name().c_str()));
    ui->tableWidget->setItem(0,1, item);
    ui->tableWidget->setItem(1, 0, new QTableWidgetItem(players.at(1)->get_icon(), players.at(1)->get_name().c_str()));
    ui->tableWidget->setItem(1,1, item1);
    ui->tableWidget->item(0, 0)->setBackgroundColor(players.at(0)->get_color());
    ui->tableWidget->sortByColumn(1, Qt::DescendingOrder);
    ui->tableWidget->setSortingEnabled(true);
    ui->tableWidget->setColumnWidth(1, 100);
    ui->tableWidget->setColumnWidth(0, size().width()- 120);

}

HighscoreDialog::~HighscoreDialog()
{
    delete ui;
}
