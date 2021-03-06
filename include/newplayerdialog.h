#ifndef NEWPLAYERDIALOG_H
#define NEWPLAYERDIALOG_H

#include <QDialog>
#include <QColorDialog>
#include <QTime>
#include <QDebug>
#include <QIcon>
#include <QFileDialog>
#include <QFrame>

namespace Ui {
class NewPlayerDialog;
}

class NewPlayerDialog : public QDialog
{
    Q_OBJECT
    
public:
    explicit NewPlayerDialog(QWidget *parent = 0);
    ~NewPlayerDialog();
    QString get_name();
    QColor get_color();
    QIcon get_icon();
    void resizeEvent(QResizeEvent *event);

private slots:
    void on_set_color_clicked();

    void on_set_icon_clicked();

    void enable_ok_button(QString);

private:
    Ui::NewPlayerDialog *ui;
    QColor _color;
    QIcon _icon;
    //Pointer to the ok button
    QPushButton *_ok_button;
};

#endif // NEWPLAYERDIALOG_H
