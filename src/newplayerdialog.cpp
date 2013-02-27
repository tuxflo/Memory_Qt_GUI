#include "include/newplayerdialog.h"
#include "ui_newplayerdialog.h"

NewPlayerDialog::NewPlayerDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::NewPlayerDialog),
    _icon("/home/tuxflo/Pictures/joris_mosh.JPG")
{
    ui->setupUi(this);
    //Generate a random color for the new Player
    QTime time = QTime::currentTime();
    qsrand((uint)time.msec());

    QPixmap pix(ui->icon->size());
    int r = qrand()%255;
    int g = qrand()%255;
    int b = qrand()%255;
    _color = QColor(r,g,b,255);
    pix.fill(_color);
    ui->color->setPixmap(pix);
    ui->icon->setPixmap(_icon.pixmap(ui->icon->size(), QIcon::Normal, QIcon::On));
}

NewPlayerDialog::~NewPlayerDialog()
{
    delete ui;
}

QString NewPlayerDialog::get_name()
{
    return ui->lineEdit->text();
}

QColor NewPlayerDialog::get_color()
{
    return _color;
}

QIcon NewPlayerDialog::get_icon()
{
    return _icon;
}

void NewPlayerDialog::on_set_color_clicked()
{
    QPixmap pix(100,100);
    _color = QColorDialog::getColor();
    pix.fill(_color);
    ui->color->setPixmap(pix);
}

void NewPlayerDialog::on_set_icon_clicked()
{
    QFileDialog icon_dialog;
    icon_dialog.exec();
}
