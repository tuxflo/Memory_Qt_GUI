#ifndef MEMORY_CARD_H
#define MEMORY_CARD_H

#include <QGraphicsObject>
#include <QGraphicsLayoutItem>
#include <QSvgRenderer>
#include <QColor>
#include <QGraphicsDropShadowEffect>
#include <QGraphicsSceneMouseEvent>
#include <QPropertyAnimation>
#include <QPainter>

#include <string>


#include "include/card.h"

//Class for the single Memory_cards

class Memory_Card : public QGraphicsObject, public QGraphicsLayoutItem
{
    Q_OBJECT
    Q_INTERFACES(QGraphicsLayoutItem) //Is needed to supress the Q_INTERFACES warning
    Q_PROPERTY(qreal rotationAngle READ rotationAngle WRITE setRotationAngle) //Is needed for the turning animation
public:
    explicit Memory_Card();
    Memory_Card(int row, int column, Card* card, std::string cover_path, QObject *parent=0);
    ~Memory_Card();


    void set_picture(const QString& picture_path);
    void set_row(int row);
    void set_column(int column);
    void set_cover(const QString& cover_path);
    void set_hover_color(const QColor& color);

    //Main methods for turning the cards
    void turn();
    void turn_back();

    //Method for selecting the card
    void set_selected(bool selected);

    //Set the animation duration
    void set_duration(int duration);

    //Size is needed for resizing the grid
    QSize get_size();

protected:
    //From QGraphicsLaoutItem
    QSizeF sizeHint(Qt::SizeHint which, const QSizeF &constraint) const;
    void setGeometry(const QRectF &rect);

    //From QGraphicsObject
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget); //here the pictures are drawn

    //For the mouse events
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    void hoverEnterEvent(QGraphicsSceneHoverEvent *event);
    void hoverLeaveEvent(QGraphicsSceneHoverEvent *event);

    //Get the rotationAngle
    qreal rotationAngle() const;

private:
    //Each card has a front and a cover picture
    QSvgRenderer *_picture;
    QSvgRenderer *_cover;

    //The pointer is needed for switching between the pictures
    QSvgRenderer *_current;

    //Each player has its own hover color
    QGraphicsDropShadowEffect *_shadow;

    //For setting the turning animation
    int _duration;
    QPropertyAnimation *_picture_animation;
    QPropertyAnimation *_cover_animation;
    //Each card should know where it is so save the values for row and column
    int _row;
    int _column;

    //For the rotationAngle property
    qreal _rotationAngle;

    //The size of the card
    QSize _size;

    bool _turned;


    
signals:
    //Emit the clicked card, ints are for row and column
    void clicked(int, int);

    //Signal that the current card is selected/deselected
    void selection_change(int, int, bool);
    
public slots:
    //Set the rotationAngle
    void setRotationAngle(qreal angle);
    void paint_cover();

};

#endif // MEMORY_CARD_H
