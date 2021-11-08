#include "balon.h"
#include <QTimer>
#include <QList>
#include <QGraphicsScene>
#include "QDebug"
#include <stdlib.h>
#include <QGraphicsItem>
#include <QList>
#include <QGraphicsTextItem>
#include "mainwindow.h"
#include "ui_mainwindow.h"

// HEDİYE ORHAN - 18010011087

int kacanbalonsayisi=0;
int patlayanbalonsayisi=0;

Balon::Balon():QObject(),QGraphicsPixmapItem()
{
    QList<QString>paths;
    paths.append(":/image/0.jpg");
    paths.append(":/image/1.jpg");
    paths.append(":/image/2.jpg");
    paths.append(":/image/3.jpg");
    paths.append(":/image/4.jpg");
    paths.append(":/image/5.jpg");
    paths.append(":/image/6.jpg");

    int indis = rand() % 7;

    QString image_path = paths[indis];
    int random_number = rand() % 900;
    setPos(random_number, 0);
    setPixmap(QPixmap(image_path).scaled(60,60));

    setTransformOriginPoint(50, 50);

    QTimer *timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(hareket()));
    timer->start(80);

}

void Balon::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    double mx, my;

    if(event->button() == Qt::LeftButton)
    {
        mx = event->pos().x();
        my = event->pos().y();
    }
    double x1 = pos().x();
    double y1 = pos().y();
    if(mx<x1+20 || mx>x1-20 || my<y1+20 || my>y1-20)
    {
        patlayanbalonsayisi +=1;
        pbs = patlayanbalonsayisi;
        qDebug()<<"PATLAYAN BALON SAYISI : " + QString::number(patlayanbalonsayisi);  // qDebug ile doğru değeleri yazıyorum ama oyun ekranında hatalı oluyor.

        setPixmap(QPixmap(":/image/patlama.jpg").scaled(60,60));

    }

    yeniBalon();



}

void Balon::hareket()
{
    setPos(x(), y()+5);
    if(pos().y() > 600)
    {
        kacanbalonsayisi+=1;
        kbs = kacanbalonsayisi;
        //qDebug()<<"KACAN BALON SAYISI : " + QString::number(kbs);
        scene()->removeItem(this);
        delete(this);
    }

}

void Balon::yeniBalon()
{

    Balon * balon = new Balon();
    scene()->addItem(balon);

}

