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
// .pro dosyasına network ve swl ekliyoruz kullanırken core gui yanına
void Dialog::on_btn_baglan_clicked()
{
    sqlitedb.setDatabaseName("C:/Users/ORHAN/Desktop/GorselProgramlama/Ders12_SQL/myDB.db");
    if(!sqlitedb.open())
    {
        QMessageBox::information(this, "HATA", "Bağlantı sağlanamadı");
    }
    else
    {
        QMessageBox::information(this, "HATA", "Bağlantı başarılı");
    }
}

void Dialog::on_btn_kayitekle_clicked()
{
    if(!sqlitedb.open())
    {
        QMessageBox::information(this, "HATA", "Lütfen veri tabanına bağlanın!");
    }
    else
    {
       QSqlQuery qry;
       qry.prepare("INSERT INTO uye values (?,?)");
       qry.addBindValue(ui->edt_uyead->text());
       qry.addBindValue(ui->edt_uyesoyad->text());
       if(qry.exec()) // çalıştırmak için.
       {
           QMessageBox::information(this, "DURUM", "Eklendi");
       }
       else
       {
           QMessageBox::information(this, "HATA", "Eklenemedi !!");
       }
    }



}

void Dialog::on_btn_kayitlistele_clicked()
{
    QSqlQuery sorgu;
    model = new QSqlQueryModel();
    if(sorgu.exec("Select * from uye"))
    {
        model->setQuery(sorgu);
        ui->tableView->setModel(model);
    }
    else
    {
         QMessageBox::information(this, "HATA", "Veri Tabanı Problemi !!");
    }

}
