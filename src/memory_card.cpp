#include "include/memory_card.h"

Memory_Card::Memory_Card()
{
}

Memory_Card::Memory_Card(int row, int column, Card* card, std::string cover_path,  QObject *parent) :
    _row(row),
    _column(column),
    _duration(400),
    _size(150, 150),
    _turned(false)
{
    _picture = new QSvgRenderer(QString(card->get_filename().c_str()), this);
    _cover = new QSvgRenderer(QString(cover_path.c_str()), this);
    _current = _cover;
    setGraphicsItem(this);
    setFlag(QGraphicsItem::ItemIsSelectable);
    setAcceptHoverEvents(true);

    _picture_animation = new QPropertyAnimation(this, "rotationAngle");
    _picture_animation->setDuration(_duration);
    _cover_animation = new QPropertyAnimation(this, "rotationAngle");
    _cover_animation->setDuration(_duration);
}

Memory_Card::~Memory_Card()
{
    //Do some cleanup here
}

QSizeF Memory_Card::sizeHint(Qt::SizeHint which, const QSizeF &constraint) const
{
    switch (which) {
    case Qt::MinimumSize:
        return QSize(50, 50);
    case Qt::PreferredSize:
        return _size + QSize(12,12);
    case Qt::MaximumSize:
        return QSizeF(1000,1000);
    default:
        break;
    }
    return constraint;
}

void Memory_Card::setGeometry(const QRectF &rect)
{
    prepareGeometryChange();
    QGraphicsLayoutItem::setGeometry(boundingRect());
    setPos(rect.topLeft());
}

QRectF Memory_Card::boundingRect() const
{
    return QRectF(0, 0, _size.width(), _size.height());
}

void Memory_Card::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option)
    Q_UNUSED(widget)
    //For mirroring the Picture
    painter->scale(-1, 1);
    _current->render(painter, QRect(-_size.width(), 0, _size.width(), _size.height()));
}

void Memory_Card::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
//    if(!_turned)
//    {
//        _current = _picture;
//        _turned = true;
//    }
//    else
//    {
//        _current = _cover;
//        _turned = false;
//    }
//    update();
    emit selection_change(_row, _column, true);
    emit clicked(_row, _column);
    event->setAccepted(true);
}

void Memory_Card::hoverEnterEvent(QGraphicsSceneHoverEvent *event)
{
    emit selection_change(_row, _column, true);
    event->setAccepted(true);
}

void Memory_Card::hoverLeaveEvent(QGraphicsSceneHoverEvent *event)
{
    emit selection_change(_row, _column, false);
    event->setAccepted(true);
}

void Memory_Card::setRotationAngle(qreal angle)
{
    if (_rotationAngle != angle)
    {
        _rotationAngle = angle;
        QPointF c = boundingRect().center();
        QTransform t;
        t.translate(c.x(), c.y());
        t.rotate(_rotationAngle, Qt::YAxis);
        t.translate(-c.x(), -c.y());
        setTransform(t);
    }
}

void Memory_Card::paint_cover()
{
    if(!_turned)
        _current = _cover;
    else
        _current = _picture;
}


qreal Memory_Card::rotationAngle() const
{
    return _rotationAngle;
}


void Memory_Card::set_duration(int duration)
{
    _duration = duration/2;
}


void Memory_Card::set_selected(bool selected)
{
    setSelected(selected);
}


void Memory_Card::turn()
{
    _picture_animation->setStartValue(0);
    _picture_animation->setEndValue(90);

    _cover_animation->setStartValue(90);
    _cover_animation->setEndValue(180);
    connect(_picture_animation, SIGNAL(finished()), this, SLOT(paint_cover()));
    connect(_picture_animation, SIGNAL(finished()), _cover_animation, SLOT(start()));
    _picture_animation->start();
    _turned = true;
}
