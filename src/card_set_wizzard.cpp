#include "include/card_set_wizzard.h"
#include "ui_card_set_wizzard.h"
#include <QList>

Card_Set_Wizzard::Card_Set_Wizzard(I_Memory *game, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Card_Set_Wizzard),
    _game(game)
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
        QStringList filter;
        filter << "thumbnail.png";
        picture_dir.setNameFilters(filter);

        for(int i=0; i< list.size(); i++)
        {
            QString icon_path = list.at(i).absoluteFilePath();
            icon_path.append("/");
            icon_path.append(filter.first());
            if(QFile(icon_path).exists()) //Add the Icon to the List if there is a thumbnail file
            {
                QListWidgetItem *item = new QListWidgetItem(QIcon(icon_path), list.at(i).fileName(), ui->listWidget);
                ui->listWidget->addItem(item);
            }
        }
        connect(ui->listWidget, SIGNAL(itemSelectionChanged()), this, SLOT(_set_num_of_cards()));

}

Card_Set_Wizzard::~Card_Set_Wizzard()
{
    qDebug() << "Card_Set_Wizzard Destructor!";
    delete _item_list;
    delete ui;
}

void Card_Set_Wizzard::on_next_button_clicked()
{
    _game->set_number_of_cards(ui->spinBox->value());
    emit card_setted();
}

void Card_Set_Wizzard::_set_num_of_cards()
{
    QList<QListWidgetItem*> itemlist;
    itemlist = ui->listWidget->selectedItems();
    QString tmp_folder_path = "./Pictures/";
    tmp_folder_path.append(itemlist.front()->text());
    tmp_folder_path.append("/svg");
    if(_game->set_folder_path(tmp_folder_path.toAscii().data()))
    {
        int num = _game->get_possible_num_cards();
        if(num%2 == 0)
        {
            //ui->spinBox->setValue(_game->get_possible_num_cards());
            //Just for testing
            ui->spinBox->setValue(4);
            ui->spinBox->setMaximum(_game->get_possible_num_cards());
        }
        else
        {
            ui->spinBox->setValue(_game->get_possible_num_cards()-1);
            ui->spinBox->setMaximum(_game->get_possible_num_cards()-1);
        }
        ui->spinBox->setDisabled(false);
        ui->next_button->setDisabled(false);
    }
    else
    {
        QMessageBox::warning(this, tr("Error"),
                                       tr("There are no Cards in %1").arg(tmp_folder_path),QMessageBox::Ok);
        ui->spinBox->setDisabled(true);
        ui->next_button->setDisabled(true);
    }

}

void Card_Set_Wizzard::on_back_button_clicked()
{
    emit back();
}
