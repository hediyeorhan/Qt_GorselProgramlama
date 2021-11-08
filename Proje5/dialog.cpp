#include "dialog.h"
#include "ui_dialog.h"
#include "QString"
#include "QMessageBox"
#include "QDebug"
#include "QSettings"
#include "QVariant"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
    yukle(); // constructor içinde çağırmazsak default değerinde açılır yine. Kaydetmez. // Arka plan rengi kaydediyor.
    baslarken(); // kendimizin combobox içine yazmasını sağlıyor.
    yukle_demirbas(); // listeye eklenen değerleri kaydediyor. Her açtığımızda oluyor.
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::baslarken()
{
    ui->cmbDemirbas->setEditable(true);
}

void Dialog::on_cmbRenk_currentIndexChanged(const QString &arg1)
{
    QString yazi = "Seçtiğiniz renk : " + arg1;
    ui->lRenk->setText(yazi);
    this->setStyleSheet("background-color:"+arg1); // arka plan rengi değiştirmek için kullanıyoruz.
}

void Dialog::on_pushButton_clicked()
{   // Kayıt defterine ekleme yapıyoruz. Kaydetmek için arka plan rengini, kapattığımızda son seçimimiz gelecek tekrar açtığımızda.
    QSettings settings("NeuGorselProg", "gpd5h");
    settings.setValue("ayarlar", ui->cmbRenk->currentIndex());
    QMessageBox::information(this, "Seçim Kaydedildi", QString::number(ui->cmbRenk->currentIndex()));
}

void Dialog::yukle()
{
    QSettings settings("NeuGorselProg", "gpd5h");
    QVariant value = settings.value("ayarlar", 0);

    int index = value.toInt();
    qDebug() <<  value <<index;

    if(index < ui->cmbRenk->count())
    {
        ui->cmbRenk->setCurrentIndex(index);
    }
    else
    {
        ui->cmbRenk->setCurrentIndex(0);
    }
}

void Dialog::on_btn_demirbas_clicked()
{
    if(ui->cmbDemirbas->findText(ui->cmbDemirbas->currentText()) < 0)
    {
        ui->cmbDemirbas->addItem(ui->cmbDemirbas->currentText());
    }
    ui->listDemirbas->addItem(ui->cmbDemirbas->currentText()); // listeye değerleri ekliyoruz.
}

void Dialog::yukle_demirbas()
{
    QSettings settings("NeuGorsel","gp5d");


    ui->cmbDemirbas->setCurrentText(settings.value("text","").toString());

    qDebug() << "fonk_yukle_demirbas" << settings.value("text","").toString();

    int combosize = settings.beginReadArray("combo");
    for (int i = 0;i < combosize; i++)
    {
        settings.setArrayIndex(i);
        ui->cmbDemirbas->addItem(settings.value("item","").toString());
    }
    settings.endArray();

    int listsize = settings.beginReadArray("list");
    for (int i = 0;i < listsize; i++)
    {
        settings.setArrayIndex(i);
        ui->listDemirbas->addItem(settings.value("item","").toString());
    }
    settings.endArray();
}

void Dialog::kaydet()
{
    QSettings settings("NeuGorsel", "gp5d");
    settings.clear();

    settings.setValue("text",ui->cmbDemirbas->currentText());

    settings.beginWriteArray("combo");
    for(int i = 0; i < ui->cmbDemirbas->count(); i++)
    {
        settings.setArrayIndex(i);
        settings.setValue("item", ui->cmbDemirbas->itemText(i));
    }
    settings.endArray();

    settings.beginWriteArray("list");
    for(int i = 0; i < ui->listDemirbas->count(); i++)
    {
        settings.setArrayIndex(i);
        settings.setValue("item", ui->listDemirbas->item(i)->text());
    }
    settings.endArray();

}

void Dialog::on_btn_sil_clicked()
{
    QList<QListWidgetItem*> items = ui->listDemirbas->selectedItems();
    foreach (QListWidgetItem* item, items)
    {
        ui->listDemirbas->removeItemWidget(item);
        delete item;
    }
}

void Dialog::on_btn_temizle_clicked()
{
    ui->cmbDemirbas->clear();
    ui->listDemirbas->clear();
    return;
}

void Dialog::on_btn_tamam_clicked()
{
    kaydet();
    accept();
    return;
}

void Dialog::on_btn_iptal_clicked()
{
    reject();
    return;
}
