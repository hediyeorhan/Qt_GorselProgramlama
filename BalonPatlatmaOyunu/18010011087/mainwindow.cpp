#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QTimer>
#include <QObject>
#include "balon.h"
#include <QBrush>
#include <QImage>
#include <QLabel>
#include "QDebug"


// HEDİYE ORHAN - 18010011087

QTimer *time;

int sayac = 0;
Balon * balon;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);


    time = new QTimer(this);
    time->setInterval(1000);
    QObject::connect(time, SIGNAL(timeout()), this, SLOT(time_timeout()));
    time->start();

    QGraphicsScene * scene = new QGraphicsScene();
    scene->setBackgroundBrush(QBrush(QImage(":/image/arkaplan.jpg")));
    balon = new Balon();
    scene->addItem(balon);

    QGraphicsView * view = new QGraphicsView(scene);

    view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setFixedSize(800, 600);
    scene->setSceneRect(0, 0, 800, 600);

    ui->graphicsView->setScene(scene);

    QTimer *timer = new QTimer();
    QObject::connect(timer, SIGNAL(timeout()), balon, SLOT(yeniBalon()));

    QObject::connect(timer, SIGNAL(timeout()), this, SLOT(yazdir()));
    timer->start(3000);

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::time_timeout()
{
    sayac++;
    ui->label_suresayac->setText(QString::number(sayac));

}

void MainWindow::yazdir()
{
    ui->label_pbs->setText(QString::number(balon->pbs));
    ui->label_kbs->setText(QString::number(balon->kbs));
}
