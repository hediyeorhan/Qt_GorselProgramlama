#include "dialog.h"
#include "ui_dialog.h"
#include "QMessageBox"
#include "QDebug"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
    ui->groupBox->setVisible(false);
}

Dialog::~Dialog()
{
    delete ui;
}


QString mail, ad, parola;


void Dialog::on_pushButton_clicked()
{
    ad = ui->lineEdit_kayit_kullaniciadi->text();
    mail = ui->lineEdit_3_kayit_mail->text();
    parola = ui->lineEdit_2_kayit_parola->text();


    if(ad == "" || mail =="" || parola == "")
        QMessageBox::information(this, "HATA !", "Eksik bilgi girdiniz. Lütfen tüm alanları eksiksiz doldurun.");
    else
        ui->groupBox->setVisible(true);
}

void Dialog::on_pushButton_2_clicked()
{
    QString giris_ad, giris_parola;

    giris_ad = ui->lineEdit_giris_ad->text();
    giris_parola = ui->lineEdit_2_giris_parola->text();

    if(giris_ad == ad && parola == giris_parola)
        QMessageBox::information(this, "HOŞGELDİNİZ", "Başarıyla giriş yaptınız.Tebrikler..");
    else if(giris_ad != ad || giris_ad == "")
        QMessageBox::information(this, "HATA !", "Kullanıcı adınızı hatalı ya da eksik girdiniz lütfen tekrar deneyin.");
    else if(giris_parola != parola || giris_parola == "")
        QMessageBox::information(this, "HATA !", "Parolanızı hatalı ya da eksik girdiniz lütfen tekrar deneyin.");
}
