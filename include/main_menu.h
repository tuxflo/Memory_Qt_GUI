#ifndef MAIN_MENU_H
#define MAIN_MENU_H

#include <QWidget>

namespace Ui {
class Main_Menu;
}

class Main_Menu : public QWidget
{
    Q_OBJECT
    
public:
    explicit Main_Menu(QWidget *parent = 0);
    ~Main_Menu();
signals:
    void new_game();
    void help();
    void quit();
private slots:
    void on_new_game_button_clicked();

    void on_Help_button_clicked();

    void on_exit_button_clicked();

private:
    Ui::Main_Menu *ui;
};

#endif // MAIN_MENU_H
