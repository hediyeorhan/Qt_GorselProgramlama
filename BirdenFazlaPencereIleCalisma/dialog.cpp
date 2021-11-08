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

void Dialog::on_btn_parentshow_clicked()
{
    // Parent Sınıf kullanarak dialog.ui kapanırsa hepsi kapanır
    Dialog2 *dialog = new Dialog2(this);
    dialog->show();
}

void Dialog::on_btn_noparentshow_clicked()
{
    // Parent sınıf kullanmadan  dialog.ui kapanırsa hepsi kapanmaz bağımsız parentten
    Dialog2 *dialog = new Dialog2();
    dialog->show();
}

void Dialog::on_btn_parentexec_clicked()
{
    Dialog2 *dialog = new Dialog2(this); // dialog2.ui kapanmadan parent yani dialog.ui kapanmıyor ve erişilmiyor.
    dialog->exec();
}

void Dialog::on_btn_noparentexec_clicked()  // parent olmadan veya olarak fark yok.!!!
{
    Dialog2 *dialog = new Dialog2(); // dialog2.ui kapanmadan parent yani dialog.ui kapanmıyor ve erişilmiyor
    dialog->exec();
}

void Dialog::on_btn_resimsec_clicked()
{
    ResimSec *dlgResim = new ResimSec(this);
    dlgResim->exec();
    // listeden seçilen resmin path'ini oku ve text edit'a yaz.
    // O pathte bulunan iconu buton üzerine koy!.
    ui->textEdit->setText(dlgResim->selected);
    ui->btn_resimsec->setIcon(QIcon(dlgResim->selected));
}
