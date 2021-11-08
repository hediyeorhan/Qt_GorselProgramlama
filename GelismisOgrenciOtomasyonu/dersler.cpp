#include "dersler.h"
#include "ui_dersler.h"

dersler::dersler(QSqlDatabase db, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::dersler)
{
    ui->setupUi(this);
    sorgu = new QSqlQuery(db);
    listele();
}

dersler::~dersler()
{
    delete ui;
}

void dersler::listele()
{
    model = new QSqlQueryModel();
    if(sorgu->exec("Select * from dersler"))
    {
        model->setQuery(*sorgu);
        ui->tableView_tumdersler->setModel(model);
    }
    else
    {
        qDebug()<<sorgu->lastError();
    }

}

void dersler::listelesecili()
{
    model2 = new QSqlQueryModel();

    if(sorgu->exec("SELECT * FROM notlar WHERE ders_kodu=? ;"))
    {
        sorgu->addBindValue(deger);
        model2->setQuery(*sorgu);
        ui->tableView_secilen->setModel(model2);
    }
    else
    {
        qDebug()<<sorgu->lastError();
    }
}

void dersler::on_pushButton_derskayit_clicked()
{
    if(ui->lineEdit_dersad->text() == "" || ui->lineEdit_derskod->text() == "")
    {
        QMessageBox::information(this, "HATA !", "Lütfen gerekli alanları doldurun..", "Tamam");
    }
    else
    {
        sorgu->prepare("insert into dersler(ders_kodu, ders_adi) values(?, ?)");
        sorgu->addBindValue(ui->lineEdit_derskod->text().toInt());
        sorgu->addBindValue(ui->lineEdit_dersad->text());
    }

    if(!sorgu->exec())
        QMessageBox::critical(this, "HATA !", "Bu kod üzerine kayıtlı ders bulunmaktadır..", "Tamam");

    listele();
}

void dersler::on_pushButton_dersguncelle_clicked()
{
    if(ui->lineEdit_dersad->text() == "" || ui->lineEdit_derskod->text() == "")
    {
        QMessageBox::information(this, "HATA !", "Lütfen gerekli alanları doldurun..", "Tamam");
    }
    else
    {
        sorgu->prepare("update dersler set ders_adi=? where ders_kodu=?");

        sorgu->addBindValue(ui->lineEdit_dersad->text());
        sorgu->addBindValue(ui->lineEdit_derskod->text().toInt());

    }
    if(!sorgu->exec())
        QMessageBox::information(this, "HATA !", "Bu kod üzerine kayıtlı ders bulunmaktadır..", "Tamam");

    listele();
}

void dersler::on_pushButton_derssil_clicked()
{
    sorgu->prepare("delete from dersler WHERE ders_kodu=?");
    sorgu->addBindValue(ui->lineEdit_derskod->text().toInt());
    if(!sorgu->exec())
        QMessageBox::critical(this, "HATA !", sorgu->lastError().text());

    listele();
}

void dersler::on_tableView_tumdersler_clicked(const QModelIndex &index)
{
    deger = model->index(index.row(), 0).data().toInt();

    ui->lineEdit_derskod->setText(model->index(index.row(), 0).data().toString());
    ui->lineEdit_dersad->setText(model->index(index.row(), 1).data().toString());
    listele();
    listelesecili();
}
