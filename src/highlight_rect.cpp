#include "include/highlight_rect.h"

Highlight_Rect::Highlight_Rect(QSize size) :
    _size(size)
{
    _rect = new QGraphicsRectItem(-5,-5, _size.width(), _size.height());
    _rect->setBrush(Qt::red);
    _blur = new QGraphicsBlurEffect;
    _blur->setBlurRadius(10);
    _blur->setEnabled(true);
    _rect->setGraphicsEffect(_blur);
    setGraphicsItem(_rect);
    _rect->setZValue(-1);

    _ani = new QPropertyAnimation(this, "opacity");
    _ani->setDuration(1600);
    _ani->setKeyValueAt(0, 0);
    _ani->setKeyValueAt(0.5, 1);
    _ani->setKeyValueAt(1, 0);
    _ani->start();
}

qreal Highlight_Rect::opacity() const
{
    return _rect->opacity();
}

void Highlight_Rect::setOpacity(qreal opacity)
{
    _rect->setOpacity(opacity);
}

void Highlight_Rect::setGeometry(const QRectF &rect)
{
    prepareGeometryChange();
    QGraphicsLayoutItem::setGeometry(rect);
    _rect->setPos(rect.topLeft());
}

QSizeF Highlight_Rect::sizeHint(Qt::SizeHint which, const QSizeF &constraint) const
{
    switch(which)
    {
    case Qt::MinimumSize:
        return QSize(40, 40);
        case Qt::PreferredSize:
        return _size + QSize(12, 12);
    case Qt::MaximumSize:
        return QSize(200,200);
    }
    return constraint;
}
