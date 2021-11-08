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

void Dialog::on_gonder_clicked()
{
    QMessageBox::information(this, "Hoşgeldiniz", "Merhaba "+ui->edtisim->text(), "Tamam");
}
