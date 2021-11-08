#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QTextStream"
#include "Ogrenci.cpp"
#include "QList"
#include "QString"

Qlist<Ogrenci*> ogrler;


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // uygulama ilk açıldığında dosya içerikleri okunsun ve ekranda görünsün :
/*
    QFile myfile("gecenler.txt");
    if(!myfile.exists())
    {
        QMessageBox::information(this, "UYARI", "Böyle bir dosya bulunmamaktadır!", "Tamam");
        return;
    }
    else if(myfile.open(QIODevice::ReadOnly))
    {
        QMessageBox::information(this, "UYARI", myfile.errorString(), "Tamam");
        return;
    }
    QTextStream stream(&myfile);
    while(!stream.atEnd()) // dosyanın sonuna gelene kadar devam et.
    {
        ui->listWidget_gecenler->addItem(stream.readLine());
    }
    myfile.close();

    QFile myfile2("kalanlar.txt");
    if(!myfile2.exists())
    {
        QMessageBox::information(this, "UYARI", "Böyle bir dosya bulunmamaktadır!", "Tamam");
        return;
    }
    else if(myfile2.open(QIODevice::ReadOnly))
    {
        QMessageBox::information(this, "UYARI", myfile2.errorString(), "Tamam");
        return;
    }
    QTextStream stream2(&myfile2);
    while(!stream2.atEnd()) // dosyanın sonuna gelene kadar devam et.
    {
        ui->listWidget_kalanlar->addItem(stream2.readLine());

    myfile2.close();*/
}

MainWindow::~MainWindow()
{
    QFile myfile("tumogrenciler.txt");
    if(!myfile.open(QIODevice::WriteOnly | QIODevice::Append)) // üstüne yazsın silmeden diye append ekledik.
    {
        QMessageBox::information(this, "UYARI", myfile.errorString(), "Tamam");
        return;
    }
    QTextStream stream(&myfile);
    Ogrenci *ogr;
    foreach(ogr, ogrler)
    {
        stream << ui->lineEdit_ad->text() + " " + ui->lineEdit_soyad->text() + " Geçme Notu : " + QString::number(ogr->GecmeNotuHesapla(ogr->vizenot, ogr->finalnot))+"\r\n";
    }


    myfile.close();
    delete ui;
}

void MainWindow::on_btn_hesapla_clicked()
{
    Ogrenci *ogr = new Ogrenci(ui->lineEdit_ad->text(), ui->lineEdit_soyad->text(), ui->lineEdit_vize->text().toInt(), ui->lineEdit_final->text().toInt());
    double gecmenotu = ogr->GecmeNotuHesapla(ui->lineEdit_vize->text().toInt(), ui->lineEdit_final->text().toInt());

    ogrler.append(ogr);
    // ogr->GecmeNotuHesapla(ogr->vizenot, ogr->finalnot);


    if(gecmenotu >= 60)
    {
        ui->listWidget_gecenler->addItem(ogr->ad + " " +ogr->soyad+ " Geçme Notu : " + QString::number(gecmenotu));
        QFile myfile("gecenler.txt");
        if(!myfile.open(QIODevice::WriteOnly | QIODevice::Append)) // üstüne yazsın silmeden diye append ekledik.
        {
            QMessageBox::information(this, "UYARI", myfile.errorString(), "Tamam");
            return;
        }
        QTextStream stream(&myfile);
        stream << ui->lineEdit_ad->text() + " " + ui->lineEdit_soyad->text() + " Geçme Notu : " + QString::number(gecmenotu)+"\r\n";
        myfile.close();
    }
    else
    {
        ui->listWidget_kalanlar->addItem(ogr->ad + " " + ogr->soyad + " Geçme Notu : " + QString::number(gecmenotu));
        QFile myfile("kalanlar.txt");
        if(!myfile.open(QIODevice::WriteOnly | QIODevice::Append))
        {
            QMessageBox::information(this, "UYARI", myfile.errorString(), "Tamam");
            return;
        }
        QTextStream stream(&myfile); // dosyayı okur ve yazar yazılacak yerleri alt satırda ekliyoruz.
        stream << ui->lineEdit_ad->text() + " " + ui->lineEdit_soyad->text() + " Geçme Notu : " + QString::number(gecmenotu) + "\r\n";
        myfile.close();
    }



    /*
    double gecmenotu;

    gecmenotu = (ui->lineEdit_vize->text().toDouble()*0.4) + (ui->lineEdit_final->text().toDouble()*0.6);

    if(gecmenotu >= 60)
    {
        ui->listWidget_gecenler->addItem(ui->lineEdit_ad->text() + " " + ui->lineEdit_soyad->text() + " Geçme Notu : " + QString::number(gecmenotu));
        QFile myfile("gecenler.txt");
        if(!myfile.open(QIODevice::WriteOnly | QIODevice::Append)) // üstüne yazsın silmeden diye append ekledik.
        {
            QMessageBox::information(this, "UYARI", myfile.errorString(), "Tamam");
            return;
        }
        QTextStream stream(&myfile);
        stream << ui->lineEdit_ad->text() + " " + ui->lineEdit_soyad->text() + " Geçme Notu : " + QString::number(gecmenotu)+"\r\n";
        myfile.close();
    }
    else
    {
        ui->listWidget_kalanlar->addItem(ui->lineEdit_ad->text() + " " + ui->lineEdit_soyad->text() + " Geçme Notu : " + QString::number(gecmenotu));
        QFile myfile("kalanlar.txt");
        if(!myfile.open(QIODevice::WriteOnly | QIODevice::Append))
        {
            QMessageBox::information(this, "UYARI", myfile.errorString(), "Tamam");
            return;
        }
        QTextStream stream(&myfile); // dosyayı okur ve yazar yazılacak yerleri alt satırda ekliyoruz.
        stream << ui->lineEdit_ad->text() + " " + ui->lineEdit_soyad->text() + " Geçme Notu : " + QString::number(gecmenotu) + "\r\n";
        myfile.close();
    }*/


}
