#ifndef BALON_H
#define BALON_H


#include <QObject>
#include <QGraphicsPixmapItem>
#include <QGraphicsItem>
#include <QGraphicsPixmapItem>
#include <QGraphicsSceneMouseEvent>


// HEDİYE ORHAN - 18010011087

class Balon: public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    Balon();
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    int kbs=0;
    int pbs=0;
public slots:
    void hareket();
    void yeniBalon();

};

#endif // BALON_H
