#ifndef HIGHLIGHT_RECT_H
#define HIGHLIGHT_RECT_H

#include <QGraphicsItem>
#include <QGraphicsLayoutItem>
#include <QGraphicsBlurEffect>
#include <QPropertyAnimation>

class Highlight_Rect : public QObject, public QGraphicsLayoutItem, public QGraphicsItem
{
    Q_OBJECT
    Q_PROPERTY(qreal opacity READ opacity WRITE setOpacity)

public:
    explicit Highlight_Rect(QSize size);

protected:
    qreal opacity() const;
    void setOpacity(qreal opacity);
    void setGeometry(const QRectF &rect);
    QSizeF sizeHint(Qt::SizeHint which, const QSizeF &constraint) const;
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

private:
    QGraphicsRectItem *_rect;
    QSize _size;
    QGraphicsBlurEffect *_blur;
    QPropertyAnimation *_ani;
signals:
    
public slots:
    
};

#endif // HIGHLIGHT_RECT_H
