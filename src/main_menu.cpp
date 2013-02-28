#include "include/main_menu.h"
#include "ui_main_menu.h"

Main_Menu::Main_Menu(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Main_Menu)
{
    ui->setupUi(this);
}

Main_Menu::~Main_Menu()
{
    qDebug() << "Main_Menu Destructor!";
    delete ui;
}

void Main_Menu::on_new_game_button_clicked()
{
    emit new_game();
}

void Main_Menu::on_Help_button_clicked()
{
    emit help();
}

void Main_Menu::on_exit_button_clicked()
{
    emit quit();
}
