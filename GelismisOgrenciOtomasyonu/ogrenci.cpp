#include "ogrenci.h"
#include "ui_ogrenci.h"

ogrenci::ogrenci(QSqlDatabase db, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ogrenci)
{
    ui->setupUi(this);
    sorgu = new QSqlQuery(db);
    listele();
}

ogrenci::~ogrenci()
{
    delete ui;
}

void ogrenci::listele()
{
    model = new QSqlQueryModel();
    if(sorgu->exec("Select * from ogrenciler"))
    {
        model->setQuery(*sorgu);
        ui->tableView->setModel(model);
    }
    else
    {
        qDebug()<<sorgu->lastError();
    }
}

void ogrenci::on_btn_yenikayit_clicked()
{
    if(ui->lineEdit_no->text() == "" || ui->lineEdit_ad->text() == "" || ui->lineEdit_soyad->text() == "")
    {
        QMessageBox::information(this, "HATA !", "Lütfen gerekli alanları doldurun..", "Tamam");
    }
    else
    {
        sorgu->prepare("insert into ogrenciler(ogr_no, ogr_ad, ogr_soyad) values(?, ?, ?)");
        sorgu->addBindValue(ui->lineEdit_no->text().toInt());
        sorgu->addBindValue(ui->lineEdit_ad->text());
        sorgu->addBindValue(ui->lineEdit_soyad->text());
    }

    if(!sorgu->exec())
        QMessageBox::critical(this, "HATA !", "Bu öğrenci no ile kayıtlı öğrenci bulunmaktadır..", "Tamam");

    listele();
}

void ogrenci::on_btn_guncelle_clicked()
{
    if(ui->lineEdit_no->text() == "" || ui->lineEdit_ad->text() == "" || ui->lineEdit_soyad->text() == "")
    {
        QMessageBox::information(this, "HATA !", "Lütfen gerekli alanları doldurun..", "Tamam");
    }
    else
    {
        sorgu->prepare("update ogrenciler set ogr_ad=?, ogr_soyad=? where ogr_no=?");

        sorgu->addBindValue(ui->lineEdit_ad->text());
        sorgu->addBindValue(ui->lineEdit_soyad->text());
        sorgu->addBindValue(ui->lineEdit_no->text().toInt());
    }

    if(!sorgu->exec())
        QMessageBox::critical(this, "HATA !", sorgu->lastError().text());

    listele();

}

void ogrenci::on_btn_sil_clicked()
{

    sorgu->prepare("delete from ogrenciler WHERE ogr_no=?");
    sorgu->addBindValue(ui->lineEdit_no->text().toInt());
    if(!sorgu->exec())
        QMessageBox::critical(this, "HATA !", sorgu->lastError().text());

    listele();

}

void ogrenci::on_tableView_clicked(const QModelIndex &index)
{
    ui->lineEdit_no->setText(model->index(index.row(), 0).data().toString());
    ui->lineEdit_ad->setText(model->index(index.row(), 1).data().toString());
    ui->lineEdit_soyad->setText(model->index(index.row(), 2).data().toString());
}
