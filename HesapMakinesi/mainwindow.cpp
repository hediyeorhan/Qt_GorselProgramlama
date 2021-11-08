#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_toplama_clicked()
{
    QString s1, s2;
    int ss1, ss2;
    s1 = ui->s1->toPlainText();
    s2 = ui->s2->toPlainText();
    ss1 = s1.toInt();
    ss2 = s2.toInt();
    QString tmp =  QString::number(ss1+ss2);
    ui->sonuc->setText(tmp);
}

void MainWindow::on_cikarma_clicked()
{
    QString s1, s2;
    int ss1, ss2;
    s1 = ui->s1->toPlainText();
    s2 = ui->s2->toPlainText();
    ss1 = s1.toInt();
    ss2 = s2.toInt();
    QString tmp =  QString::number(ss1-ss2);
    ui->sonuc->setText(tmp);
}

void MainWindow::on_carpma_clicked()
{
    QString s1, s2;
    int ss1, ss2;
    s1 = ui->s1->toPlainText();
    s2 = ui->s2->toPlainText();
    ss1 = s1.toInt();
    ss2 = s2.toInt();
    QString tmp =  QString::number(ss1*ss2);
    ui->sonuc->setText(tmp);
}

void MainWindow::on_bolme_2_clicked()
{
    QString s1, s2;
    int ss1;
    float ss2;
    s1 = ui->s1->toPlainText();
    s2 = ui->s2->toPlainText();
    ss1 = s1.toInt();
    ss2 = s2.toFloat();
    QString tmp =  QString::number(ss1/ss2);
    ui->sonuc->setText(tmp);
}
