#ifndef MEMORY_CARD_H
#define MEMORY_CARD_H

#include <QGraphicsObject>
#include <QGraphicsLayoutItem>

#include "include/card.h"

//Class for the single Memory_cards

class Memory_Card : public QGraphicsObject, public QGraphicsLayoutItem, public Card
{
    Q_OBJECT
public:
    explicit Memory_Card();
protected:
    //From QGraphicsLaoutItem
    QSizeF sizeHint(Qt::SizeHint which, const QSizeF &constraint) const;
    void setGeometry(const QRectF &rect);

    //From QGraphicsObject
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
private:

    
signals:
    
public slots:
    
};

#endif // MEMORY_CARD_H
