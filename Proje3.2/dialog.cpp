#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
    connect(ui->btnconnect, &QPushButton::clicked, this, &Dialog::yazDebugEkran);
}

Dialog::~Dialog()
{
    delete ui;
}


void Dialog::yazDebugEkran()
{
    QMessageBox::information(this, "Buton tıklama zamanı", "Butona tıklanma zamanı : "+ QDateTime::currentDateTime().toString());
    accept(); // Pencereyi kapatır..
}


void Dialog::on_btneditor_clicked()
{
    qDebug() <<"yazDebugEkran ile butonun tıklnma zamanını yazdıracağız.";
    yazDebugEkran();
}
