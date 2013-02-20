#include "include/card_set_wizzard.h"
#include "ui_card_set_wizzard.h"
#include <QList>

Card_Set_Wizzard::Card_Set_Wizzard(Memory *game, QWidget *parent) :
    QWidget(parent),
    _game(game),
    ui(new Ui::Card_Set_Wizzard)
{
    ui->setupUi(this);

    //Disable next button until a valid card set is choosen
    ui->next_button->setDisabled(true);
    ui->spinBox->setSingleStep(2);
    ui->spinBox->setMinimum(2);

    ui->listWidget->setIconSize(QSize(100,100));

    _item_list = new QList<QListWidgetItem*>;

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
                QListWidgetItem *item = new QListWidgetItem(QIcon(filename), list.at(i).fileName(), ui->listWidget);
            }
        }
        connect(ui->listWidget, SIGNAL(itemSelectionChanged()), this, SLOT(_set_num_of_cards()));
//    ui->listView->setViewMode(QListView::IconMode);
//    ui->listView->setIconSize(QSize(200, 200));

//    _model = new QStandardItemModel(this);
//    _item_list = new QList<QStandardItem*>;

//    //Checkout the different card folders
//    QDir picture_dir("./Pictures");
//    if(!picture_dir.exists())
//    {
//        QMessageBox::critical(this, tr("Error"),
//                                       tr("Could not find Picture folder!\nPlease make sure that it exists in the current directory."),QMessageBox::Ok);
//        QApplication::exit(-1);
//    }
//    picture_dir.setFilter(QDir::Dirs | QDir::NoSymLinks | QDir::NoDot | QDir::NoDotDot);
//    QFileInfoList list = picture_dir.entryInfoList();

//    for(int i=0; i< list.size(); i++)
//    {
//        QString filename = list.at(i).absoluteFilePath();
//        filename.append("/thumbnail.png");
//        QFile file(filename);
//        if(!file.exists())
//        {
//            QMessageBox::warning(this, tr("Warning"), tr("Could not find thumbnail.png in folder: %1").arg(filename), QMessageBox::Ok);
//            list.removeAt(i);
//            i--;
//        }
//        else
//        {
//            _item_list->push_back(new QStandardItem(QIcon(filename), list.at(i).fileName()));
//        }
//    }
//    _model->appendColumn(*_item_list);
//    ui->listView->setModel(_model);
}

Card_Set_Wizzard::~Card_Set_Wizzard()
{
    delete ui;
}

void Card_Set_Wizzard::on_next_button_clicked()
{
    emit card_setted();
}

void Card_Set_Wizzard::_set_num_of_cards()
{
    QList<QListWidgetItem*> itemlist;
    itemlist = ui->listWidget->selectedItems();
    QString tmp_folder_path = "./Pictures/";
    tmp_folder_path.append(itemlist.front()->text());
    tmp_folder_path.append("/svg");
    qDebug() << tmp_folder_path;
    if(_game->set_folder_path(tmp_folder_path.toAscii().data()))
    {
        int num = _game->get_possible_num_cards();
        if(!num%2)
        {
            ui->spinBox->setValue(num);
            ui->spinBox->setMaximum(num);
        }
        else
        {
            ui->spinBox->setValue(num-1);
            ui->spinBox->setMaximum(num-1);
        }
        ui->next_button->setDisabled(false);
    }
    else
    {
        ui->spinBox->setValue(0);
        ui->next_button->setDisabled(true);
    }
}

void Card_Set_Wizzard::on_back_button_clicked()
{
    emit back();
}
