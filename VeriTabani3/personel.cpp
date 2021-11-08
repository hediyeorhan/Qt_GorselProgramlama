#include "personel.h"
#include "ui_personel.h"

personel::personel(QSqlDatabase db, QWidget *parent)
    QDialog(parent),
    ui(new Ui::personel)
{
    ui.setupUi(this);
    sorgu = new QSqlQuery(db);
    listele();
}

personel::personel()
{
    delete ui;
}

void personel::listele()
{
    model = new QSqlQueryModel();
    if(sorgu->exec("Select * from personel"))
    {
        model->setQuery(*sorgu);
        ui->tableView->setModel(model);
    }
    else
    {
        qDebug()<<sorgu->lastError();
    }
}

void personel::on_pushButton_kaydet_clicked()
{
    sorgu->prepare("insert into personel(personel_ad, personel_soyad, departman_id) values(?, ?, ?)");
    sorgu->addBindValue(ui->lineEdit_personelad->text());
    // diğerleri de aynen ekleniyor.

    if(sorgu->exec())
        QMessageBox::critical(this, "HATA !", sorgu->lastError().text());
}

void personel::on_pushButton_guncelle_clicked()
{
    sorgu->prepare("update personel set personel_ad=?, personel_soyad=?, departman_id=? where personel_id=?");
    sorgu->addBindValue(ui->lineEdit->text()); // diğerleri de aynı ekleniyor.

    if(sorgu->exec())
        QMessageBox::critical(this, "HATA !", sorgu->lastError().text());

    listele();

}

void personel::on_pushButton_sil_clicked()
{
     sorgu->prepare("delete from personel WHERE personel_id=?");
     sorgu->addBindValue(ui->lineEdit_personelid->text().toInt());
     if(sorgu->exec())
         QMessageBox::critical(this, "HATA !", sorgu->lastError().text());

     listele();

}

void personel::on_tableView_clicked(const QModelIndex &index)
{
    ui->lineEdit->setText(model->index(index.row(), 0).data().toString()); // 1, 2, 3 olarak diğerleri de alınıyor.
}
