#include "include/qplayer.h"

QPLayer::QPLayer()
{
}

QPLayer::QPLayer(QString name) :
    Player(name.toAscii().data())
{
}

void QPLayer::set_color(const QColor &color)
{
    _color = color;
}

QColor QPLayer::get_color()
{
    return _color;
}

void QPLayer::set_icon(const QIcon &icon)
{
    _icon = icon;
}

QIcon QPLayer::get_icon()
{
    return _icon;
}
