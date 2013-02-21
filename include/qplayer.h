#ifndef QPLAYER_H
#define QPLAYER_H
#include <QString>
#include <QIcon>
#include "include/player.h"

//QPLayer is used for handeling the players of the Memory_Qt_GUI
//it adds some special propertys like color and picture to the existing ones of the player class

class QPLayer : public Player
{
public:
    QPLayer();
    QPLayer(QString name);
    ~QPLayer(){}
    void set_color(const QColor& color);
    QColor get_color();
    void set_icon(const QIcon& icon);
    QIcon get_icon();
    void set_name(QString name);
protected:
private:
    QIcon _icon;
    QColor _color;
};

#endif // QPLAYER_H
