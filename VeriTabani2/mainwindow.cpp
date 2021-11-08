#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->tabWidget->setEnabled(false);
    sqlitedb.setDatabaseName("C:/Users/ORHAN/Desktop/GorselProgramlama/Ders13_VeriTabani/kutuphane.db");
    if(!sqlitedb.open())
        ui->statusBar->showMessage("Durum: Veritabanı bağlantısı başarısız.");
    else
        ui->statusBar->showMessage("Durum: Veritabanı bağlantısı başarılı.");
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_btn_oturumac_clicked()
{
    QSqlQuery qry;
    qry.prepare("SELECT uye_ad FROM uye WHERE uye_ad=? AND sifre=? ;");
    qry.addBindValue(ui->lineEdit_kullaniciadi->text());
    qry.addBindValue(ui->lineEdit_sifre->text());
    qry.exec();

    int sayac=0;
    while(qry.next())
        sayac++;
    if(sayac==1)
    {
        ui->tabWidget->setEnabled(true);
        ui->statusBar->showMessage("Durum : Kullanıcı Eşleşti, Oturum Açıldı");
    }
    else
    {
        ui->statusBar->showMessage("Durum : Oturum Açılmadı !!");
        qDebug() <<qry.lastError();
    }
}

void MainWindow::on_pushButton_clicked()
{
    QSqlQuery qry;
    qry.prepare("insert into odunc (kitap_id, uye_id, sure" "values(?,?,?)");
    qry.addBindValue(ui->lineEdit_kitapid->text());
    qry.addBindValue(ui->lineEdit_uyeid->text());
    qry.addBindValue(15);
    if(qry.exec())
    {
        ui->statusBar->showMessage("Durum : Odunc verme islemi başarılı");
    }
    else
    {
        qDebug() << qry.lastError();
        ui->statusBar->showMessage("Durum : Odunc verme islemi başarısız");
    }

}
