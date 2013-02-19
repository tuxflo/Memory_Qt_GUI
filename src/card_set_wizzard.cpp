#include "include/card_set_wizzard.h"
#include "ui_card_set_wizzard.h"
#include <QList>

Card_Set_Wizzard::Card_Set_Wizzard(Memory *game, QWidget *parent) :
    QWidget(parent),
    _game(game),
    ui(new Ui::Card_Set_Wizzard)
{
    ui->setupUi(this);
    ui->listView->setViewMode(QListView::IconMode);
    ui->listView->setIconSize(QSize(200, 200));

    _model = new QStandardItemModel(this);
    _item_list = new QList<QStandardItem*>;

    //Checkout the different card folders
    QDir picture_dir("./Pictures");
    if(!picture_dir.exists())
    {
        QMessageBox::critical(this, tr("Error"),
                                       tr("Could not find Picture folder!\nPlease make sure that it exists in the current directory."),QMessageBox::Ok);
        QApplication::exit(-1);
    }
    picture_dir.setFilter(QDir::Dirs | QDir::NoSymLinks | QDir::NoDot | QDir::NoDotDot);
    QFileInfoList list = picture_dir.entryInfoList();

    for(int i=0; i< list.size(); i++)
    {
        QString filename = list.at(i).absoluteFilePath();
        filename.append("/thumbnail.png");
        QFile file(filename);
        if(!file.exists())
        {
            QMessageBox::warning(this, tr("Warning"), tr("Could not find thumbnail.png in folder: %1").arg(filename), QMessageBox::Ok);
            list.removeAt(i);
            i--;
        }
        else
        {
            _item_list->push_back(new QStandardItem(QIcon(filename), list.at(i).fileName()));
        }
    }
    _model->appendColumn(*_item_list);
    ui->listView->setModel(_model);
}

Card_Set_Wizzard::~Card_Set_Wizzard()
{
    delete ui;
}

void Card_Set_Wizzard::on_next_button_clicked()
{
    QModelIndexList index = ui->listView->selectionModel()->selectedIndexes();
    if(!index.isEmpty())
    {
        qDebug() <<  _model->itemFromIndex(index.first())->text();
        emit card_setted();
    }
}
