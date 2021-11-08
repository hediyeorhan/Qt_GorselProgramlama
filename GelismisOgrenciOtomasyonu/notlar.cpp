#include "notlar.h"
#include "ui_notlar.h"

notlar::notlar(QSqlDatabase db, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::notlar)
{
    ui->setupUi(this);
    sorgu = new QSqlQuery(db);
    listele();
}

notlar::~notlar()
{
    delete ui;
}

void notlar::listele()
{
    model = new QSqlQueryModel();
    if(sorgu->exec("Select * from ogrenciler"))
    {
        model->setQuery(*sorgu);
        ui->tableView_tumogrenciler->setModel(model);
    }
    else
    {
        qDebug()<<sorgu->lastError();
    }

    model2 = new QSqlQueryModel();
    if(sorgu->exec("Select * from dersler"))
    {
        model2->setQuery(*sorgu);
        ui->tableView_tumdersler->setModel(model2);
    }
    else
    {
        qDebug()<<sorgu->lastError();
    }

    model3 = new QSqlQueryModel();
    if(sorgu->exec("Select * from notlar"))
    {
        model3->setQuery(*sorgu);
        ui->tableView_tum->setModel(model3);
    }
    else
    {
        qDebug()<<sorgu->lastError();
    }
}

void notlar::on_tableView_tumogrenciler_clicked(const QModelIndex &index)
{
    ui->lineEdit_ogrno->setText(model->index(index.row(), 0).data().toString());
}

void notlar::on_tableView_tumdersler_clicked(const QModelIndex &index)
{
    ui->lineEdit_derskod->setText(model2->index(index.row(), 0).data().toString());
}

void notlar::on_tableView_tum_clicked(const QModelIndex &index)
{
    ui->lineEdit_ogrno->setText(model3->index(index.row(), 0).data().toString());
    ui->lineEdit_derskod->setText(model3->index(index.row(), 1).data().toString());
    ui->lineEdit_vizenot->setText(model3->index(index.row(), 2).data().toString());
    ui->lineEdit_finalnot->setText(model3->index(index.row(), 3).data().toString());
}

void notlar::on_pushButton_derskayit_clicked()
{
    if(ui->lineEdit_ogrno->text() == "" || ui->lineEdit_derskod->text() == "" || ui->lineEdit_vizenot->text() == "" || ui->lineEdit_finalnot->text() == "")
    {
        QMessageBox::information(this, "HATA !", "Lütfen gerekli alanları doldurun..", "Tamam");
    }
    else
    {
        sorgu->prepare("insert into notlar(ogr_no, ders_kodu, vize_not, final_not, gecme_notu) values(?, ?, ?, ?, ?)");

        sorgu->addBindValue(ui->lineEdit_ogrno->text().toInt());
        sorgu->addBindValue(ui->lineEdit_derskod->text().toInt());
        sorgu->addBindValue(ui->lineEdit_vizenot->text().toInt());
        sorgu->addBindValue(ui->lineEdit_finalnot->text().toInt());
        sorgu->addBindValue((ui->lineEdit_vizenot->text().toInt()*0.4) + (ui->lineEdit_finalnot->text().toInt()*0.6));
    }

    if(!sorgu->exec())
        QMessageBox::critical(this, "HATA !", sorgu->lastError().text());

    listele();
}
