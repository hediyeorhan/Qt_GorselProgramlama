#include "dialog.h"
#include "ui_dialog.h"

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

void Dialog::on_btn_hesapla_clicked()
{
    QString ad, dersad, vn, fn;
    ad = ui->ograd->text();
    dersad = ui->dersad->text();
    vn = ui->vnot->text();
    fn = ui->fnot->text();
    if(ad == "" || dersad =="" || vn == "" || fn == "")
        ui->text_sonuc->setText("EKSİK BİLGİ GİRDİNİZ !! LÜTFEN KONTROL EDİNİZ VE TEKRAR DENEYİNİZ..");
    else
    {
        int vizen, finaln, gecme_notu;
        vizen = vn.toInt();
        finaln = fn.toInt();

        gecme_notu = (vizen * 0.4) + (finaln * 0.6);

        if(gecme_notu >= 60)
            ui->text_sonuc->setText(ad +" isimli öğrenci "+dersad + " dersinden geçmiştir.");
        else
            ui->text_sonuc->setText(ad +" isimli öğrenci "+dersad + " dersinden kalmıştır.");
    }


}
