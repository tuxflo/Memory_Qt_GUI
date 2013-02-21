#ifndef MEMORYGRAPHICSWIDGET_H
#define MEMORYGRAPHICSWIDGET_H

#include <QGraphicsWidget>
#include <QGraphicsGridLayout>

class MemoryGraphicsWidget : public QGraphicsWidget
{
    Q_OBJECT
public:
    explicit MemoryGraphicsWidget(QObject *parent = 0);
protected:
private:
    QGraphicsGridLayout *_grid;
signals:
    
public slots:
    
};

#endif // MEMORYGRAPHICSWIDGET_H
