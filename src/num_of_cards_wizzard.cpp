#include "include/num_of_cards_wizzard.h"
#include "ui_num_of_cards_wizzard.h"

Num_of_cards_wizzard::Num_of_cards_wizzard(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Num_of_cards_wizzard)
{
    ui->setupUi(this);
}

Num_of_cards_wizzard::~Num_of_cards_wizzard()
{
    delete ui;
}
