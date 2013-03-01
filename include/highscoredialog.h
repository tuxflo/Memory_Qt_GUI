#ifndef HIGHSCOREDIALOG_H
#define HIGHSCOREDIALOG_H

#include <QDialog>
#include <QSettings>
namespace Ui {
class HighscoreDialog;
}

class HighscoreDialog : public QDialog
{
    Q_OBJECT
    
public:
    explicit HighscoreDialog(QWidget *parent = 0);
    ~HighscoreDialog();
    
private:
    Ui::HighscoreDialog *ui;
};

#endif // HIGHSCOREDIALOG_H
