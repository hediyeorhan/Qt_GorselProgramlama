#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFile>
#include <QDebug>
#include <iostream>
#include <fstream>

// HEDIYE ORHAN - 18010011087
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    sqlitedb.setDatabaseName("C:/Users/ORHAN/Desktop/GorselProgramlama/18010011087_Quiz2/quizveritabani.db");
    if(!sqlitedb.open())
        ui->statusBar->showMessage("Durum: Veritabanı bağlantısı başarısız.");
    else
        ui->statusBar->showMessage("Durum: Veritabanı bağlantısı başarılı.");

    sorgu = new QSqlQuery(sqlitedb);
    veritabaninaekle();
    tableViewGoruntule();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::veritabaninaekle()
{
    int id, gecmenot;
    QString ad, soyad;
    QFile dosya("ogrenciler.txt");
    QTextStream yazi(&dosya);
    while(!yazi.atEnd())
    {
        QString satir = yazi.readLine();
        id = satir.split(" ")[0].toInt();
        ad = satir.split(" ")[1];
        soyad = satir.split(" ")[2];
        gecmenot = satir.split(" ")[3].toInt();
        qDebug()<< id;
        qDebug()<< ad;
        qDebug()<< soyad;
        qDebug()<< gecmenot;
        if(gecmenot >= 60)
        {
            sorgu->prepare("insert into gecenler(ogr_id, ogr_ad, ogr_soyad, gecme_notu) values(?, ?, ?, ?)");
            sorgu->addBindValue(id);
            sorgu->addBindValue(ad);
            sorgu->addBindValue(soyad);
            sorgu->addBindValue(gecmenot);
        }
        else
        {
            sorgu->prepare("insert into kalanlar(ogr_id, ogr_ad, ogr_soyad, gecme_notu) values(?, ?, ?, ?)");
            sorgu->addBindValue(id);
            sorgu->addBindValue(ad);
            sorgu->addBindValue(soyad);
            sorgu->addBindValue(gecmenot);
        }

    }
}

void MainWindow::tableViewGoruntule()
{
    model = new QSqlQueryModel();
    if(sorgu->exec("Select * from gecenler"))
    {
        model->setQuery(*sorgu);
        ui->tableView_gecenler->setModel(model);
    }
    else
    {
        qDebug()<<sorgu->lastError();
    }

    model2 = new QSqlQueryModel();
    if(sorgu->exec("Select * from kalanlar"))
    {
        model2->setQuery(*sorgu);
        ui->tableView_kalanlar->setModel(model2);
    }
    else
    {
        qDebug()<<sorgu->lastError();
    }
}

void MainWindow::on_pushButton_clicked()
{

    if(ui->lineEdit_gecmenot->text() == " " || ui->lineEdit_id->text() == " " || ui->lineEdit_ad->text() == " " || ui->lineEdit_soyad->text() == " ")
    {
        QMessageBox::information(this, "HATA !!", "Lütfen boş alanları doldurun..", "Tamam");
    }
    else
    {
        if(ui->lineEdit_gecmenot->text().toInt() >= 60)
        {
            sorgu->prepare("insert into gecenler(ogr_id, ogr_ad, ogr_soyad, gecme_notu) values(?, ?, ?, ?)");
            sorgu->addBindValue(ui->lineEdit_id->text().toInt());
            sorgu->addBindValue(ui->lineEdit_ad->text());
            sorgu->addBindValue(ui->lineEdit_soyad->text());
            sorgu->addBindValue(ui->lineEdit_gecmenot->text().toInt());
        }
        else
        {
            sorgu->prepare("insert into kalanlar(ogr_id, ogr_ad, ogr_soyad, gecme_notu) values(?, ?, ?, ?)");
            sorgu->addBindValue(ui->lineEdit_id->text().toInt());
            sorgu->addBindValue(ui->lineEdit_ad->text());
            sorgu->addBindValue(ui->lineEdit_soyad->text());
            sorgu->addBindValue(ui->lineEdit_gecmenot->text().toInt());
        }
    }

    if(sorgu->exec())
        QMessageBox::critical(this, "HATA !", sorgu->lastError().text());
}
