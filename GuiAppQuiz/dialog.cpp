#include "dialog.h"
#include "ui_dialog.h"
#include "QDebug"
#include "QMessageBox"
#include "QString"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
}

Dialog::~Dialog()
{
    delete ui;
}


int sayi, ustdeger;
int ds1, ds2;

void Dialog::on_btn_sayiuret_clicked()
{

    ustdeger = ui->spinBox->value();
    sayi = rand()%(ustdeger - 0)+0;

    QString string = QString::number(sayi);

    ui->label_usbilgi->setText(string);

}

void Dialog::on_btn_yarismayibaslat_clicked()
{
    ui->listWidget_oyuncu1->clear();
    ui->listWidget_oyuncu2->clear();
    int tahmin1, tahmin2;
    QString d2, d1;
    QString oyuncusayi;

    QObject* obj = ui->groupBox_oyuncu;
        QList<QRadioButton*> liste = obj->findChildren<QRadioButton*>(QString(), Qt::FindDirectChildrenOnly);
        foreach(QRadioButton* rd, liste)
        {
            if(rd->isChecked())
            {
                oyuncusayi = rd->text();
            }
        }

        if(oyuncusayi == "Tek Oyunculu")
        {
            tahmin1 = rand()%(ustdeger - 0)+ 0;
            ds1++;
            QString t1 = QString::number(tahmin1);
            ui->listWidget_oyuncu1->addItem((t1));
            while(tahmin1 != sayi)
            {
                ds1++;
                tahmin1 = rand()%(ustdeger - 0)+ 0;
                t1 = QString::number(tahmin1);
                ui->listWidget_oyuncu1->addItem((t1));

            }
            d1 = QString::number(ds1);
            ui->listWidget_oyuncu1->addItem(("Deneme Sayısı : "+d1));

             QMessageBox::information(this, "Tebrikler!!", "Tebrikler, " + d1 + " denemede KAZANDINIZ !!" );
        }
        else
        {
            ds1 = 0;
            tahmin1 = rand()%(ustdeger - 0)+ 0;
            ds1++;
            tahmin2 = rand()%(ustdeger - 0)+ 0;
            ds2++;
            QString t2 = QString::number(tahmin2);
            ui->listWidget_oyuncu2->addItem((t2));
            QString t1 = QString::number(tahmin1);
            ui->listWidget_oyuncu1->addItem((t1));
            while(tahmin2 != sayi)
            {
                ds2++;
                tahmin2 = rand()%(ustdeger - 0)+ 0;
                QString t2 = QString::number(tahmin2);
                ui->listWidget_oyuncu2->addItem((t2));

            }
            while(tahmin1 != sayi)
            {
                ds1++;
                tahmin1 = rand()%(ustdeger - 0)+ 0;
                t1 = QString::number(tahmin1);
                ui->listWidget_oyuncu1->addItem((t1));

            }
            d1 = QString::number(ds1);
            ui->listWidget_oyuncu1->addItem(("Deneme Sayısı : "+d1));
            d2 = QString::number(ds2);
            ui->listWidget_oyuncu2->addItem(("Deneme Sayısı : "+d2));

            if(ds1 < ds2)
            {
                QMessageBox::information(this, "Tebrikler!!", "Tebrikler Oyuncu 1, " + d1 + " denemede KAZANDINIZ !!" );

            }
            else if(ds2 < ds1)
            {
                QMessageBox::information(this, "Tebrikler!!", "Tebrikler Oyuncu 2, " + d2 + " denemede KAZANDINIZ !!" );

            }
            else
            {
                QMessageBox::information(this, "Tebrikler!!", "Durum berabere." );
            }
        }


}

void Dialog::on_spinBox_valueChanged(int arg1)
{
    QString string = QString::number(arg1);

    ui->label_bilgi->setText("0 ile " + string +" sayıları arasında sayı tahmin oyunu başlıyor.");
}

void Dialog::on_radioButton_tek_clicked()
{
    ui->groupBox_oyuncu1->setEnabled(true);
    ui->groupBox_oyuncu2->setEnabled(false);
}

void Dialog::on_radioButton_iki_clicked()
{
    ui->groupBox_oyuncu1->setEnabled(true);
    ui->groupBox_oyuncu2->setEnabled(true);
}
