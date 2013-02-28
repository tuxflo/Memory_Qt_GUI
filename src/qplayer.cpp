#include "include/qplayer.h"

QPLayer::QPLayer()
{
}

QPLayer::QPLayer(QString name) :
    Player(name.toAscii().data())
{
}

QPLayer::~QPLayer()
{
    qDebug() << "QPlayer Destructor!";
}

void QPLayer::set_color(const QColor &color)
{
    _color = color;
}

QColor QPLayer::get_color()
{
    return _color;
}

void QPLayer::set_icon(const QIcon& icon)
{
    _icon = icon;
}

QIcon QPLayer::get_icon()
{
    return _icon;
}

void QPLayer::set_name(QString name)
{
    Player::set_name(name.toAscii().data());
}
