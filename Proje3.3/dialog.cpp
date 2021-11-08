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

void Dialog::on_btnCheckable_clicked()
{
    qDebug()<<"Tıklandı mı? : " << ui->btnCheckable->isChecked();
}

void Dialog::on_btnIsCheck_clicked()
{
    QString mesaj;
    if (ui->btnCheckable->isChecked())
        mesaj = "Evet aktif ..";
    else
        mesaj = "Hayır aktif değil ..";

    QMessageBox::information(this, "Tıklandı Mı?", mesaj, "Tamam");
}

void Dialog::on_btnAutoRepeat_clicked()
{

    cout<<"Butona basili durumda !!"<<endl;
}

void Dialog::on_btnAutoRepeatDegistir_clicked()
{
    bool durum = !ui->btnAutoRepeat->autoRepeat();
    ui->btnAutoRepeat->setAutoRepeat(durum);
    qDebug()<< "autoRepeat buton durumu:" << ui->btnAutoRepeat->autoRepeat();
}

void Dialog::on_btnDefault_clicked()
{
    QMessageBox::information(this, "Durum", "Default Klavyeden Tıklandı.");
}

void Dialog::on_btnDefaultDegistir_clicked()
{
    ui->btnDefault->setAutoDefault(false);
    ui->btnAutoRepeat->setAutoDefault(true);

    QMessageBox::information(this, "Default Durumu", "Default Durumu Değişti");

}
