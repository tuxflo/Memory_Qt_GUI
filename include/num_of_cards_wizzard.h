#ifndef NUM_OF_CARDS_WIZZARD_H
#define NUM_OF_CARDS_WIZZARD_H

#include <QWidget>

namespace Ui {
class Num_of_cards_wizzard;
}

class Num_of_cards_wizzard : public QWidget
{
    Q_OBJECT
    
public:
    explicit Num_of_cards_wizzard(QWidget *parent = 0);
    ~Num_of_cards_wizzard();
    
private:
    Ui::Num_of_cards_wizzard *ui;
};

#endif // NUM_OF_CARDS_WIZZARD_H
