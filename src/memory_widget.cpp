#include "include/memory_widget.h"
#include "ui_memory_widget.h"

Memory_Widget::Memory_Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Memory_Widget)
{
    ui->setupUi(this);
}

Memory_Widget::~Memory_Widget()
{
    delete ui;
}
