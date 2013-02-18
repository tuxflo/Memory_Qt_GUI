#ifndef MEMORY_WIDGET_H
#define MEMORY_WIDGET_H

#include <QWidget>

namespace Ui {
class Memory_Widget;
}

class Memory_Widget : public QWidget
{
    Q_OBJECT
    
public:
    explicit Memory_Widget(QWidget *parent = 0);
    ~Memory_Widget();
    
private:
    Ui::Memory_Widget *ui;
};

#endif // MEMORY_WIDGET_H
